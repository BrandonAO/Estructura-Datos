#pragma once
#include "Mazo.h"
#include "Blackjack.h"

class Sistema
{
private:
	Blackjack* blackjack;

public:
	Sistema();
	void iniciarSistema();
	void leerArchivoAdmin();
	void leerArchivoCartas();
	void leerArchivoJugadores();
};

