#pragma once
#include <string>
#include "Carta.h"

using namespace std;
class Jugador
{
private:
	string nombre;
	string rut;
	Carta mano;
	short int partidasGanadas;
	int billetera;
public:
	Jugador();
	Jugador(string,int,Carta,short int,int);
	~Jugador();

};



