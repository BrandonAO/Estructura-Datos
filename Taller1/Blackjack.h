#pragma once

#include "Jugador.h" 
#include "Croupier.h"
#include "Mazo.h"
class Blackjack
{

private:
	Jugador jugadores[100];
	Croupier croupier;
	Mazo mazo;
public:
	Blackjack();
};

