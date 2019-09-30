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
	void agregarCarta(Carta&);
	Carta sacarCarta();
	void mezclarMazo();
	void imprimirCartas();
	~Mazo();


};

