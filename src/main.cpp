#include "Automata.h"

int main() {
	Automata automata;
	automata.on();
	automata.coin(10);
	automata.coin(10);
	automata.coin(10);
	automata.coin(10);
	automata.choice("Tea");
	automata.cook();

	return 0;
}