#include "Croupier.h"
using namespace std;
#include <iostream>


Croupier::Croupier() {

	this->mano = new Carta[10];
	this->cantActual = 0;
}

Croupier::~Croupier()
{
}
bool Croupier::ingresarCarta(Carta car) {
	if (cantActual < 10) {
		mano[cantActual] = car;
		cantActual++;
		return true;
	}
	cout << "No se puede ingresar mas cartas, la mano se encuentra llena" << endl;
	return false;
}
