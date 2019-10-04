#pragma once
#include "Carta.h"
using namespace std;
class Croupier
{
private:
	Carta* mano;
	int cantActual;
public:
	Croupier();
	~Croupier();
	bool ingresarCarta(Carta car);
};

