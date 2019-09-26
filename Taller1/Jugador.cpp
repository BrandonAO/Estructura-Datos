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
	mano = Carta();
}

Jugador::Jugador(string _nombre, int _rut, Carta _mano, short int _partidasGanadas, int _idBilletera)
{
	nombre = _nombre;
	rut = _rut;
	mano = _mano;
	partidasGanadas = _partidasGanadas;
	idBilletera = _idBilletera;
}

Jugador::~Jugador()
{

}

void Jugador::setNombre(string nombre)
{
	nombre = nombre;
}
