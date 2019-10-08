#include "Jugador.h"
#include <iostream>
#include <stdio.h>
#include "Carta.h"



Jugador::Jugador()
{
	nombre = "";
	rut = "";
	partidasGanadas = 0;
	idBilletera = 0;
	mano = new Carta[10];
	puntaje = 0;
	monto = 0;
	cartasActual = 0;
	cantJugadoresTotales = 0;

}

Jugador::Jugador(string nombre, string rut, int monto, int idBilletera, short int partidasGanadas)
{
	this->nombre = nombre;
	this->rut = rut;
	this->partidasGanadas = partidasGanadas;
	this->idBilletera = idBilletera;
	this->mano = new Carta[10];
	this->puntaje = 0;
	this->monto = monto;
	this->cartasActual = 0;
	this->cantJugadoresTotales = 0;
}

Jugador::Jugador(string nombre, string rut, int idBilletera)
{
	this->nombre = nombre;
	this->rut = rut;
	this->idBilletera = idBilletera;
	this->mano = new Carta[10];
}

Jugador::~Jugador()
{
}

string Jugador::getNombre()
{
	return nombre;
}

void Jugador::setNombre(string nombre)
{
	this->nombre = nombre;
}

string Jugador::getRut()
{
	return rut;
}

Carta& Jugador::getMano()
{
	return *mano;
}

int Jugador::getIdBilletera()
{
	return idBilletera;
}

int Jugador::getPartidasGanadas()
{
	return partidasGanadas;
}

int Jugador::getMonto()
{
	return monto;
}
int Jugador::getCantJugadoresTotales()
{
	return cantJugadoresTotales;
}

int Jugador::getPuntaje()
{
	for (int i = 0; i < cartasActual; i++) {
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
	return puntaje;
}

void Jugador::setMonto(int monto)
{
	this->monto += monto;
}
void Jugador::setcantJugadoresTotales(int cantJugadoresTotales)
{
	this->cantJugadoresTotales += cantJugadoresTotales;
}
void Jugador::setMontoMenos(int monto)
{
	this->monto -= monto;
}

bool Jugador::ingresarCarta(Carta car) {
	if (cartasActual < 10) {
		mano[cartasActual] = car;
		cartasActual++;
		return true;
	}
	cout << "No se puede ingresar mas cartas, la mano se encuentra llena" << endl;
	return false;
}
void Jugador::setPartidasGanadas(int partidasGanadasX) {
	partidasGanadas = partidasGanadas + partidasGanadasX;
}
