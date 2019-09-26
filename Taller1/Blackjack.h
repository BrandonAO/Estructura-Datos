#pragma once
#include "Jugador.h"
#include "Mazo.h"
#include "Croupier.h"

class Blackjack
{

private:
	Jugador* vectorJugadores;
	Croupier croupier;
	Mazo mazo;
public:
	Blackjack();
};

