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
	mano = new Carta[6];
	puntaje = 0;
}

Jugador::Jugador(string _nombre, string _rut, int _monto, int _idBilletera, short int _partidasGanadas)
{
	nombre = _nombre;
	rut = _rut;
	partidasGanadas = _partidasGanadas;
	idBilletera = _idBilletera;
	puntaje = 0;
}

Jugador::~Jugador()
{
}

void Jugador::setNombre(string nombre)
{
	nombre = nombre;
}
