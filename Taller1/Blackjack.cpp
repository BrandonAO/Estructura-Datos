#include "Blackjack.h"
#include "Croupier.h"
#include "Admin.h"
#include "Jugador.h"
#include <iostream>

Blackjack::Blackjack()
{
	this->croupier = Croupier();
	this->mazo = Mazo();
	this->cantActual = 0;
	this->max = 6; //maximo de jugadores en mesa, minimo 1
	this->jugadores = new Jugador[max];
}

Blackjack::~Blackjack() {

}

Mazo& Blackjack::getMazo()
{
	return mazo;
}

bool Blackjack::agregarJugador(Jugador& jug) {
	if (cantActual >= max) {
		cout << "* No se pueden agregar mas jugadores a la mesa. " << endl;
		return false;
	}

	if (jug.getMonto() < 5000) {
		cout << "* No se pueden agregar al jugador porque tiene menos de 5.000 en su billetera, por favor cargue saldo. " << endl;
		return false;
	}
	this->jugadores[cantActual] = jug;
	cantActual++;
	return true;
}

//metodo que elimina al jugador segun rut
bool Blackjack::eliminarJugador(string rut)
{
	for (int i = 0; i < max; i++) {
		if (jugadores[i].getRut().compare(rut) == 0) {
			cout << "Encontrado" << endl;
			cout << "Jugador rut: " << jugadores[i].getRut() << endl;
			//aca se hace la eliminacion
			
			return true;
		}
	}
	cout << "No encontrado" << endl;
	return false;

}

void Blackjack::imprimirJugadores() {
	for (int i = 0; i < max; i++) {
		cout << "Nombre: " << jugadores[i].getNombre() << "   Id: " << jugadores[i].getMonto() << endl;
	}




}




