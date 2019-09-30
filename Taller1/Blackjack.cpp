#include "Blackjack.h"
#include "Croupier.h"

Blackjack::Blackjack()
{
	this->croupier = Croupier();
	this->mazo = Mazo();
	this->cantActual = 0;
	this->max = 6;
	this->jugadores = new Jugador[max];
	

}

Blackjack::~Blackjack() {

}

Mazo& Blackjack::getMazo()
{
	return mazo;
}

void Blackjack::agregarJugador(Jugador& jug) {
	if (cantActual < max) {
		this->jugadores[cantActual] = jug;
		cantActual++;
		
	}
}