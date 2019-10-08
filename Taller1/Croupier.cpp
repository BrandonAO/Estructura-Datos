#include "Croupier.h"
using namespace std;
#include <iostream>


Croupier::Croupier() {

	this->mano = new Carta[10];
	this->cantActual = 0;
	this->puntaje = 0;
}

Croupier::~Croupier()
{
}
int Croupier::getCantActual()
{
	return cantActual;
}
int Croupier::getPuntaje()
{
	calcularPuntaje();
	return puntaje;
}
void Croupier::calcularPuntaje()
{
	for (int i = 0; i < cantActual; i++) {
		if (mano[i].getValor().compare("A") == 0) {
			if (puntaje + 11 <= 21) {
				puntaje += 11;
			}
			if (puntaje + 1 <= 21) {
				puntaje++;
			}
			else {
				puntaje++;
			}
		}
		if (mano[i].getValor().compare("J") == 0 || mano[i].getValor().compare("Q") == 0 || mano[i].getValor().compare("K") == 0) {
			puntaje += 10;
		}
		puntaje += stoi(mano[i].getValor());
	}
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
