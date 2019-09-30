#pragma once

#include "Jugador.h" 
#include "Croupier.h"
#include "Mazo.h"
#include "Admin.h";
class Blackjack
{

private:
	Jugador *jugadores;
	Admin* administradores;
	int cantActual;
	int cantActualAdmin;
	int max;
	int maxAdmin;
	Croupier croupier;
	Mazo mazo;
public:
	Blackjack();
	~Blackjack();
	Mazo& getMazo();
	bool agregarJugador(Jugador&);
	void agregarJugador(Jugador&);
	void agregarAdmin(Admin& );
	void imprimirAdmin();
	bool buscarAdmin(string rut, string id);
	bool buscarJugador(int idBilletera);
};

