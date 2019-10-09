#pragma once
#include <string>
#include "Carta.h"

using namespace std;
class Jugador
{
private:
	string nombre;
	string rut;
	Carta* mano;
	short int partidasGanadas;
	int idBilletera;
	int monto;
	int puntaje;
	int cartasActual;
	int cantJugadoresTotales;
	bool retiroRonda;
public:
	Jugador();
	Jugador(string, string, int, int, short int);
	Jugador(string, string, int);
	~Jugador();
	bool ingresarCarta(Carta);
	int getCartasActual();
	void setPartidasGanadas(int partidasGanadasX);
	void setRetiroRonda(bool);
	bool getRetiroRonda();
	string getNombre();
	string getRut();
	Carta& getMano();
	int getIdBilletera();
	int getPartidasGanadas();
	int getMonto();
	int getCantJugadoresTotales();
	int getPuntaje();
	void setMonto(int monto);
	void setcantJugadoresTotales(int cantJugadoresTotales);
	void setMontoMenos(int monto);
	void setNombre(string nombre);
};



