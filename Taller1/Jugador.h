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
public:
	Jugador();
	Jugador(string, string, int, int, short int);
	Jugador(string, string, int);
	~Jugador();
	bool ingresarCarta(Carta);
	void setPartidasGanadas(int partidasGanadasX);
	string getNombre();
	string getRut();
	Carta& getMano();
	int getIdBilletera();
	int getPartidasGanadas();
	int getMonto();
	int getPuntaje();
	void setMonto(int monto);
	void setMontoMenos(int monto);
	void setNombre(string nombre);
};



