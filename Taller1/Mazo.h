#pragma once
#include "Carta.h"
class Mazo
{
private:
	int cantActual;
	int max;
	Carta *mazo;
public:
	Mazo();
	Mazo();
	void agregarCarta(Carta&);
	~Mazo();


};

