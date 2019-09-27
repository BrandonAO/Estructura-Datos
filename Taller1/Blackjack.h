#pragma once
#include "Jugador.h"
#include "Croupier.h"
#include "Mazo.h"
class Blackjack
{

private:
	Jugador *jugadores;
	Croupier croupier;
	Mazo mazo;
public:
	Blackjack();
};

