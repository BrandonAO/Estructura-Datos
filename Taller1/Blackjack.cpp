#include "Blackjack.h"
#include "Croupier.h"
#include "Admin.h"
#include "Jugador.h"
#include <iostream>

Blackjack::Blackjack()
{
	this->croupier = Croupier();
	this->mazo = Mazo();
	this->cantActual = 0;
	this->max = 6; //maximo de jugadores en mesa, minimo 1
	this->jugadores = new Jugador[max];
}

Blackjack::~Blackjack() {

}

Mazo& Blackjack::getMazo()
{
	return mazo;
}

bool Blackjack::agregarJugador(Jugador& jug) {
	if (cantActual >= max) {
		return false;
	}

	if (jug.getMonto() < 5000) {
		return false;
	}
	this->jugadores[cantActual] = jug;
	cantActual++;
	return true;
}




