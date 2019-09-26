#include "Jugador.h"
#include <iostream>
#include <stdio.h>
#include "Carta.h"

Jugador::Jugador() 
{
	nombre = "";
	rut = "";
	partidasGanadas = 0;
	billetera = 0;
	mano = Carta();
}

Jugador::Jugador(string _nombre, int _rut, Carta _mano, short int _partidasGanadas, int _billetera)
{
	nombre = _nombre;
	rut = _rut;
	mano = _mano;
	partidasGanadas = _partidasGanadas;
	billetera = _billetera;
}

Jugador::~Jugador()
{

}

void Jugador::setNombre(string nombre)
{
	nombre = nombre;
}
