// Copyright 2024 Alexander Klyuev

#pragma once
#include <string>
#include <map>

class Automata {
 public:
    enum STATES {
        OFF,
        WAIT,
        ACCEPT,
        CHECK,
        COOK
    };
    void on();
    void off();
    void coin(int amount);
    std::map<std::string, int> etMenu();
    STATES getState();
    int getCash();
    std::string getSelectedDrink();
    void choice(std::string drinkName);
    void cancel();
    void cook();
    Automata();

 private:
    STATES state;
    int cash;
    std::map<std::string, int> menu;
    std::string selectedDrink;
    void finish();
};
