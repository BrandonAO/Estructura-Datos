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

	void menuPrincipal();

	void pausa();

	void menuPrincipalIniciarPartida();

	void menuPrincipalConfiguracion();

	void consultarSaldo();

	void CargarSaldo();

	
	void agregarAdmin(Admin&);
	void imprimirAdmin();
	bool buscarAdmin(string rut, string id);
	bool buscarJugador(int idBilletera);
	bool buscarJugadorSaldo(int idBilletera, int saldo);
	void editarJugador();
	bool buscarJugadorEditar(string rut, string numero);
	void eliminarJugadorMesa();
	bool eliminarJugador(string rut);
	void agregarJugador(Jugador&);
	void registrarJugador();
	int asignarBilletera();
};

