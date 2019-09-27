#include "Mazo.h"
#include "Carta.h"

Mazo::Mazo()
{
	this->cantActual = 0;
	this->max =104;
	this->mazo= new Carta[max];
}

Mazo::~Mazo()
{

}
void Mazo::agregarCarta(Carta& car) {
	if (cantActual < max) {
		this->mazo[cantActual] = car;
		cantActual++;
	}
}
