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
	this->cantActualAdmin = 0;
	this->maxAdmin = 20;
	this->max = 20;
	this->jugadores = new Jugador[max];
	this->administradores = new Admin[max];
	

}

Blackjack::~Blackjack() {

}

Mazo& Blackjack::getMazo()
{
	return mazo;
}

bool Blackjack::agregarJugador(Jugador& jug) {
	if (cantActual >= max) {
		return false;
	}

	if (jug.getMonto() < 5000) {
		return false;
	}
	this->jugadores[cantActual] = jug;
	cantActual++;
	return true;
}
void Blackjack::agregarJugador(Jugador& jug) {
	if (cantActual < max) {
		this->jugadores[cantActual] = jug;
		cantActual++;
		
	}
}
void Blackjack::agregarAdmin(Admin& admin) {
	if (cantActualAdmin < maxAdmin) {
		this->administradores[cantActualAdmin] = admin;
		cantActualAdmin++;

	}
}
void Blackjack::imprimirAdmin()
{
	for (int i = 0; i < cantActualAdmin; i++) {
		cout << "Rut: " << administradores[i].getRut() << "   Id: " << administradores[i].getId() << endl;
	}
}

bool Blackjack::buscarAdmin(string rut, string id)
{
	for (int i = 0; i < cantActualAdmin; i++) {
		if (administradores[i].getRut().compare(rut)==0 && administradores[i].getId().compare(id)==0) {
			cout << "Encontrado" << endl;
			return true;

		}
		else {
			cout << "No encontrado" << endl;
			return false;
		}
	}

}

bool Blackjack::buscarJugador(int idBilletera)
{
		for (int i = 0; i < cantActual; i++) {
		if (jugadores[i].getIdBilletra() == idBilletera) {
			cout << "Encontrado" << endl;
			cout << "Nombre: " << jugadores[i].getNombre() <<"idBilletera: "<< jugadores[i].getIdBilletra() <<"Saldo disponible:" << jugadores[i].getMonto() << endl;
			return true;
		}
		else {
			cout << "No encontrado" << endl;
			return false;
		}
	}

}


