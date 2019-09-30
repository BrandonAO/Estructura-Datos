#pragma once

#include "Jugador.h" 
#include "Croupier.h"
#include "Mazo.h"
class Blackjack
{

private:
	Jugador *jugadores;
	int cantActual;
	int max;
	Croupier croupier;
	Mazo mazo;
public:
	Blackjack();
	~Blackjack();
	Mazo& getMazo();
};

