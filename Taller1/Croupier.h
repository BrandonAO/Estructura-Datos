#pragma once
#include "Carta.h"
using namespace std;
class Croupier
{
private:
	Carta* mano;
	int cantActual;
	int puntaje;

	void calcularPuntaje();

public:
	Croupier();
	~Croupier();
	int getCantActual();
	int getPuntaje();
	bool ingresarCarta(Carta car);
};

