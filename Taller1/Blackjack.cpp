#include "Blackjack.h"
#include "Croupier.h"

Blackjack::Blackjack(Croupier croupier, Mazo mazo)
{
	this->croupier = Croupier();
	this->mazo = Mazo();
	this->cantActual = 0;
	this->max = 100;
	this->jugadores = new Jugador[max];
	

}

Blackjack::~Blackjack()
{
}
