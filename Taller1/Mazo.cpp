#include "Mazo.h"
#include "Carta.h"
Mazo::Mazo()
{
	max = 0;
	cantActual = 0;
	mazo = new Carta[104];
}

Mazo::Mazo(int _max)
{
	cantActual = 0;
	max = _max;
	mazo = new Carta[104];
}

Mazo::~Mazo()
{
}
