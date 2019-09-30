#include "Mazo.h"
#include "Carta.h"
#include <cstdlib>
#include <iostream>

Mazo::Mazo()
{
	cantActual = 0;
	max = 104;
	mazo = new Carta[104];
}

Mazo::~Mazo()
{

}
void Mazo::agregarCarta(Carta &car) {
	if (cantActual < max) {
		this->mazo[cantActual] = car;
		cantActual++;
		cout << cantActual << endl;
	}
}

Carta Mazo::sacarCarta() {
	int ultima = cantActual;
	cantActual--;
	return mazo[ultima];
}

void Mazo::mezclarMazo() {
	for (int i = 0; i < cantActual; ++i) {
		int random = rand() % cantActual;
		Carta swap = mazo[i];
		mazo[i] = mazo[random];
		mazo[random] = swap;
	}
}

void Mazo::imprimirCartas() {
	for (int i = 0; i < cantActual; i++) {
		cout << "Pinta: " << mazo[i].getPinta() << "   Valor: " << mazo[i].getValor() << endl;
	}
}