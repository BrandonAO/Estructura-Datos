#pragma once
#include "Jugador.h"
#include "Mazo.h"
#include "Croupier.h"

class Blackjack
{

private:
	Jugador* listaJugadores;
	Croupier croupier;
	Mazo mazo;
public:
	Blackjack();
};

