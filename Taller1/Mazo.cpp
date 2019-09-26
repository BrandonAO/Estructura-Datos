#include "Mazo.h"
#include "Carta.h"
Mazo::Mazo()
{
	mazo = Carta();
}

Mazo::Mazo(Carta _mazo)
{
	mazo = _mazo;
}

Mazo::~Mazo()
{
}
