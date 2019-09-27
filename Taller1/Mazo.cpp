#include "Mazo.h"
#include "Carta.h"

Mazo::Mazo()
{
	max = 0;
	cantActual = 0;
	mazo = new Carta[104];
}

Mazo::Mazo(int _max)
Mazo::~Mazo()
{

}
void Mazo::agregarCarta(Carta& car) {
	if (cantActual < max) {
		this->mazo[cantActual] = car;
		cantActual++;
	}
}
