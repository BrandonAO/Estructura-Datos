#pragma once
#include "Mazo.h"
#include "Blackjack.h"

class Sistema
{
private:
	Blackjack* blackjack;
	Jugador* jugadores;
	int cantJugadores;
	int max;


public:
	Sistema();
	void iniciarSistema();

	
	void leerArchivoAdmin();
	void leerArchivoCartas();

	void leerArchivoJugadores();

	void consultarSaldo();

	

	


	

	void agregarJugador(Jugador&);
	void registrarJugador();
	int asignarBilletera();
};

