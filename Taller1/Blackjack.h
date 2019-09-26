#pragma once
#include "Jugador.h"
#include "Croupier.h"
#include "Mazo.h"
class Blackjack
{
	
	
private:
	Jugador* vectorJugadores[6];
	Croupier croupier;
	Mazo mazo;
public:
	Blackjack();
	Blackjack(Jugador,Carta,Mazo);
	~Blackjack();


};

