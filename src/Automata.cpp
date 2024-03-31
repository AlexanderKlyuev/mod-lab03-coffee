#include "Automata.h"

Automata::Automata() {
	state = OFF;
	cash = 0;
	menu["Tea"] = 40;
	menu["Latte"] = 50;
	menu["Espresso"] = 40;
	menu["Hot chocolate"] = 70;
	menu["Hot milk"] = 60;
}

void Automata::cook() {
	if (state == CHECK) {
		cash -= menu[selectedDrink];
		state = COOK;
		finish();
	}
}

void Automata::finish() {
	if (state == COOK) {
		selectedDrink.clear();
		state = WAIT;
	}
}

void Automata::on() {
	if (state == OFF) {
		state = WAIT;
	}
}

void Automata::off() {
	if (state == WAIT) {
		state = OFF;
	}
}

void Automata::coin(int amount) {
	if (state = WAIT) {
		state = ACCEPT;
	}

	if (state = ACCEPT) {
		cash += amount;
	}
}

std::map<std::string, int> Automata::etMenu() {
	return menu;
}

Automata::STATES Automata::getState() {
	return state;
}

int Automata::getCash()
{
	return cash;
}

std::string Automata::getSelectedDrink()
{
	return selectedDrink;
}

void Automata::choice(std::string drinkName) {
	if (!menu.count(drinkName) == 0) {
		return;
	}

	if (state == ACCEPT && cash >= menu[drinkName]) {
		state = CHECK;
		selectedDrink = drinkName;
	}
}

void Automata::cancel() {
	if (state == ACCEPT || state == CHECK) {
		selectedDrink.clear();
		state = WAIT;
		cash = 0;
	}
}