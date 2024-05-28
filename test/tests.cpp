// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "Automata.h"

TEST(automata, turnOn) {
    Automata automata;
    automata.on();
    Automata::STATES automataState = automata.getState();
    EXPECT_EQ(Automata::STATES::WAIT, automataState);
}

TEST(automata, turnOff) {
    Automata automata;
    automata.on();
    automata.off();
    Automata::STATES automataState = automata.getState();
    EXPECT_EQ(Automata::STATES::OFF, automataState);
}

TEST(automata, insertCash) {
    Automata automata;
    automata.on();
    automata.coin(10);
    Automata::STATES automataState = automata.getState();
    int automataCash = automata.getCash();
    EXPECT_EQ(Automata::STATES::ACCEPT, automataState);
    EXPECT_EQ(10, automataCash);
}

TEST(automata, buyDrink) {
    Automata automata;
    automata.on();
    automata.coin(50);
    automata.choice("Tea");
    automata.cook();
    Automata::STATES automataState = automata.getState();
    int automataCash = automata.getCash();
    EXPECT_EQ(Automata::STATES::WAIT, automataState);
    EXPECT_EQ(10, automataCash);
}

TEST(automata, cancelAccept) {
    Automata automata;
    automata.on();
    automata.coin(50);
    automata.cancel();
    Automata::STATES automataState = automata.getState();
    int automataCash = automata.getCash();
    std::string automataSelectedDrink = automata.getSelectedDrink();
    EXPECT_EQ(Automata::STATES::WAIT, automataState);
    EXPECT_EQ(0, automataCash);
    EXPECT_EQ("", automataSelectedDrink);
}

TEST(automata, cancelCheck) {
    Automata automata;
    automata.on();
    automata.coin(50);
    automata.choice("Tea");
    automata.cancel();
    Automata::STATES automataState = automata.getState();
    int automataCash = automata.getCash();
    std::string automataSelectedDrink = automata.getSelectedDrink();
    EXPECT_EQ(Automata::STATES::WAIT, automataState);
    EXPECT_EQ(0, automataCash);
    EXPECT_EQ("", automataSelectedDrink);
}

TEST(automata, turnOnWhenAlreadyOn) {
    Automata automata;
    automata.on();
    automata.on();
    Automata::STATES automataState = automata.getState();
    EXPECT_EQ(Automata::STATES::WAIT, automataState);
}

TEST(automata, insufficientCash) {
    Automata automata;
    automata.on();
    automata.coin(30);
    automata.choice("Tea");
    Automata::STATES automataState = automata.getState();
    std::string automataSelectedDrink = automata.getSelectedDrink();
    EXPECT_EQ(Automata::STATES::ACCEPT, automataState);
    EXPECT_EQ("", automataSelectedDrink);
}

TEST(automata, invalidChoice) {
    Automata automata;
    automata.on();
    automata.coin(50);
    automata.choice("Mocha");
    Automata::STATES automataState = automata.getState();
    std::string automataSelectedDrink = automata.getSelectedDrink();
    EXPECT_EQ(Automata::STATES::ACCEPT, automataState);
    EXPECT_EQ("", automataSelectedDrink);
}

TEST(automata, cookWhenOff) {
    Automata automata;
    automata.on();
    automata.coin(50);
    automata.choice("Tea");
    automata.off();
    automata.cook();
    Automata::STATES automataState = automata.getState();
    int automataCash = automata.getCash();
    std::string automataSelectedDrink = automata.getSelectedDrink();
    EXPECT_EQ(Automata::STATES::WAIT, automataState);
    EXPECT_EQ(10, automataCash);
    EXPECT_EQ("", automataSelectedDrink);
}
