// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "Automata.h"

TEST(automata, turnOn) {
	Automata automata;
	automata.on();
	STATES automataState = automata.getState();
	EXPECT_EQ(STATES::WAIT, automataState);
}

TEST(automata, turnOff) {
	Automata automata;
	automata.on();
	automata.off();
	STATES automataState = automata.getState();
	EXPECT_EQ(STATES::OFF, automataState);
}

TEST(automata, insertCash) {
	Automata automata;
	automata.on();
	automata.cash(10);
	STATES automataState = automata.getState();
	int automataCash = automata.getCash();
	EXPECT_EQ(STATES::ACCEPT, automataState);
	EXPECT_EQ(10, automataCash);
}

TEST(automata, buyDrink) {
	Automata automata;
	automata.on();
	automata.cash(50);
	automata.choice("Tea");
	automata.cook();
	STATES automataState = automata.getState();
	int automataCash = automata.getCash();
	EXPECT_EQ(STATES::WAIT, automataState);
	EXPECT_EQ(10, automataCash);
}

TEST(automata, cancelAccept) {
	Automata automata;
	automata.on();
	automata.cash(50);
	automata.cancel;
	STATES automataState = automata.getState();
	int automataCash = automata.getCash();
	std::string automataSelectedDring = automata.getSelectedDrink();
	EXPECT_EQ(STATES::WAIT, automataState);
	EXPECT_EQ(0, automataCash);
	EXPECT_EQ("", automataSelectedDring);
}

TEST(automata, cancelCheck) {
	Automata automata;
	automata.on();
	automata.cash(50);
	automata.choice("Tea");
	automata.cancel;
	STATES automataState = automata.getState();
	int automataCash = automata.getCash();
	std::string automataSelectedDring = automata.getSelectedDrink();
	EXPECT_EQ(STATES::WAIT, automataState);
	EXPECT_EQ(0, automataCash);
	EXPECT_EQ("", automataSelectedDring);
}
