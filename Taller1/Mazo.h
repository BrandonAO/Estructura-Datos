#pragma once
#include "Carta.h"
class Mazo
{
private:
	int max;
	int cantActual;
	Carta *mazo;
public:
	Mazo();
	void agregarCarta(Carta&);
	~Mazo();


};

