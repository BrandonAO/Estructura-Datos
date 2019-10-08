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
			//****falta iniciar partida
	void agregarJugadorMesa();
	void eliminarJugadorMesa();
			//****falta terminar partida

		//Jugadores On-fire:
			//*****falta
	void imprimirCartas();

		//Configuracion: debe pedir clave antes de mostrar el siguiente menú.
	void CargarSaldo();
	void consultarSaldo();
	void registrarJugador();
	int asignarBilletera();
	void editarJugador();
	bool buscarJugadorEditar(string rut, string numero);

	//Metodos para los arreglos
	void agregarAdmin(Admin&);
	void agregarJugador(Jugador&);
	void imprimirAdmin();
	bool buscarAdmin(string rut, string id);
	bool buscarJugador(int idBilletera);
	bool buscarJugadorSaldo(int idBilletera, int saldo);

};

