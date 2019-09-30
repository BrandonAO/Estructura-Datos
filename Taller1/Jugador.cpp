#include "Jugador.h"
#include <iostream>
#include <stdio.h>
#include "Carta.h"



Jugador::Jugador()
{
	nombre = "";
	rut = "";
	partidasGanadas=0;
	idBilletera = 0;
	mano = new Carta[10];
	puntaje = 0;

}

Jugador::Jugador(string nombre, string rut, int monto, int idBilletera, short int partidasGanadas)
{
	this->nombre = nombre;
	this->rut = rut;
	this->partidasGanadas = partidasGanadas;
	this->idBilletera = idBilletera;
	this->mano = new Carta[10];
	this->puntaje = 0;

}

Jugador::~Jugador()
{
}

string Jugador::getNombre()
{
	return nombre;
}

int Jugador::getIdBilletra()
{
	return idBilletera;
}

int Jugador::getMonto()
{
	return monto;
}

