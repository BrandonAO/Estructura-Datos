#pragma once
#include "Mazo.h"
#include "Blackjack.h"

class Sistema
{
private:
	Blackjack* blackjack;
	Jugador* jugadores;
	Admin* administradores;
	int cantJugadores;
	int max;
	int maxAdmin;
	int cantActualAdmin;


public:
	Sistema();
	void iniciarSistema();
	void leerArchivoAdmin();
	void leerArchivoCartas();
	void leerArchivoJugadores();
	void consultarSaldo();
	void agregarAdmin(Admin&);
	void imprimirAdmin();
	bool buscarAdmin(string rut, string id);
	bool buscarJugador(int idBilletera);
	void agregarJugador(Jugador&);
	void registrarJugador();
	int asignarBilletera();
};

