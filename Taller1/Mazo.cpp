#include "Mazo.h"
#include "Carta.h"
#include <cstdlib>
#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include "time.h"

Mazo::Mazo()
{
	cantActual = 0;
	max = 104;
	mazo = new Carta[104];
}

Mazo::~Mazo()
{

}
void Mazo::agregarCarta(Carta& car) {
	if (cantActual < max) {
		this->mazo[cantActual] = car;
		cantActual++;

	}
}

Carta Mazo::sacarCarta() {
	//int random = rand() % cantActual;
	//Carta carta = mazo[random];
	//mazo[random] = mazo[cantActual - 1];
	cantActual--;
	return mazo[cantActual];
}

void Mazo::mezclarMazo() {
	srand((unsigned int)time(0));
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < cantActual; ++i) {
			int random = rand() % cantActual;
			Carta swap = mazo[i];
			mazo[i] = mazo[random];
			mazo[random] = swap;
		}
	}

}


void Mazo::imprimirCartas() {
	for (int i = 0; i < cantActual; i++) {
		cout << "Pinta: " << mazo[i].getPinta() << "   Valor: " << mazo[i].getValor() << endl;
	}
}