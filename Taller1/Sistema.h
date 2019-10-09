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
	int ultimaId;


public:
	Sistema();
	void iniciarSistema();

	//Metodos para lectura
	void leerArchivoAdmin();
	void leerArchivoCartas();
	void leerArchivoJugadores();
	//Metodos menu principal
	void menuPrincipal();
	void pausa();
	void menuPrincipalIniciarPartida();
	void menuPrincipalConfiguracion();

	//Metodos para el menu

	//Iniciar partida:
	void agregarJugadorMesa();
	void eliminarJugadorMesa();
	void terminarPartida();// falta implementar



	//Jugadores On-fire:
	void jugadoresOnFire();


	//Configuracion: debe pedir clave antes de mostrar el siguiente menú.
	void CargarSaldo();
	void consultarSaldo();
	void registrarJugador();
	void editarJugador();
	bool buscarJugadorEditar(string, string);

	//Metodos para los arreglos
	void agregarAdmin(Admin&);
	void agregarJugador(Jugador&);
	void imprimirAdmin();
	bool buscarAdmin(string, string);
	bool buscarJugador(int);
	bool buscarJugadorSaldo(int, int);
	void ordenarJugadores(int, int);
	void merge(int, int, int);

	//Utilidades:
	void escrituraArchivoJugadores();
};

