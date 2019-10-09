#pragma once

#include "Jugador.h" 
#include "Croupier.h"
#include "Mazo.h"
#include "Admin.h"

class Blackjack
{

private:
	Jugador* jugadores;
	int cantActual;
	int max;
	Croupier croupier;
	Mazo mazo;
	int apuestas[6];
public:
	Blackjack();
	~Blackjack();
	Mazo& getMazo();
	bool agregarJugador(Jugador&);
	bool eliminarJugador(string rut);
	bool eliminarTodosJugadores();
	void imprimirJugadores();
	//Metodos para el jugar
	void partida();
	bool verificarGanador(int,bool);
	int getCantActual();
};

