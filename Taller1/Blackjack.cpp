#include "Blackjack.h"
#include "Croupier.h"
#include "Admin.h"
#include "Jugador.h"
#include <iostream>
using namespace std;

Blackjack::Blackjack()
{
	this->croupier = Croupier();
	this->mazo = Mazo();
	this->cantActual = 0;
	this->max = 6; //maximo de jugadores en mesa, minimo 1
	this->jugadores = new Jugador[max];
}

Blackjack::~Blackjack() {

}

Mazo& Blackjack::getMazo()
{
	return mazo;
}

bool Blackjack::agregarJugador(Jugador& jug) {
	if (cantActual >= max) {
		cout << "* No se pueden agregar mas jugadores a la mesa. " << endl;
		return false;
	}

	if (jug.getMonto() < 5000) {
		cout << "* No se pueden agregar al jugador porque tiene menos de 5.000 en su billetera, por favor cargue saldo. " << endl;
		return false;
	}
	this->jugadores[cantActual] = jug;
	cantActual++;
	return true;
}

//metodo que elimina al jugador segun rut
bool Blackjack::eliminarJugador(string rut)
{
	for (int i = 0; i < cantActual; i++) {
		if (jugadores[i].getRut().compare(rut) == 0) {
			cout << "Encontrado" << endl;
			cout << "Jugador rut: " << jugadores[i].getRut() << endl;

			jugadores[i] = jugadores[cantActual - 1];
			cantActual--;

			return true;
		}
	}

	cout << "No encontrado" << endl;
	return false;

}

void Blackjack::imprimirJugadores() {
	for (int i = 0; i < max; i++) {
		cout << "Nombre: " << jugadores[i].getNombre() << "   Id: " << jugadores[i].getMonto() << endl;
	}




}
// iniciar partida

void Blackjack::partida() {

	cout << "Iniciar Partida: " << endl;
	cout << "Repartiendo cartas: " << endl;
	bool terminoPartida = false;
	// apuestas por jugador
	for (int i = 0; i < cantActual; i++) {
		while (true) {
			int montoApuesta = 0;
			cout << "Apuestas:" << endl;
			cout << "Jugador " << jugadores[i].getNombre() << ":" << endl;
			cout << "Saldo Disponible: " << jugadores[i].getMonto() << endl;
			cout << "Ingresar monto a apostar: " << endl;

			cin >> montoApuesta;
			if (montoApuesta <= jugadores[i].getMonto()) {
				apuestas[i] = montoApuesta;
				jugadores[i].setMontoMenos(montoApuesta);
				break;
			}
			else {
				cout << "El monto ingresado excede de su saldo." << endl;

			}
		}


	}
	//reparte al jugador
	for (int i = 0; i < cantActual; i++) {
		bool cartasMano = jugadores[i].ingresarCarta(mazo.sacarCarta());
		cartasMano = jugadores[i].ingresarCarta(mazo.sacarCarta());
	}
	//reparte al croupier
	bool cartasMano = croupier.ingresarCarta(mazo.sacarCarta());

	// si gana solo con las cartas que se repartieron

	if (verificarGanador(21)) {
		return;
	}
	//sigue partida
	for (int i = 0; i < cantActual; i++) {
		cout << "Jugador" << jugadores[i].getNombre() << " Rendirse [1], Sacar carta [2], No sacar carta [3] " << endl;
		int opcion = 0;
		cin >> opcion;
		if (opcion == 1) {
			//rendirse
			jugadores[i].setMonto(apuestas[i] / 2);
			eliminarJugador(jugadores[i].getRut());
			cantActual--;
			break;
		}

		if (opcion == 2) {
			//sacar carta
			bool masCartas = true;
			while (masCartas = true) {
				cout << "Jugador" << i + 1 << "¿sacar carta? Si [1], No [2]  " << endl;
				int opcion2 = 0;
				cin >> opcion2;
				if (opcion2 == 1) {
					cartasMano = jugadores[i].ingresarCarta(mazo.sacarCarta());
					if (verificarGanador(21)) {
						return;
					}
				}
				if (opcion2 == 2) {
					masCartas = false;
					break;
				}

			}


		}
		if (opcion == 3) {
			//no sacar carta
		}
	}
	//sacar cartas croupier > 16


	while (croupier.getPuntaje() < 16) {
		bool cartasMano = croupier.ingresarCarta(mazo.sacarCarta());
	}

	verificarGanador(croupier.getPuntaje());

}




bool Blackjack::verificarGanador(int comparador)
{
	bool terminoPartida = false;
	for (int i = 0; i < cantActual; i++) {

		if (jugadores[i].getPuntaje() == comparador) {
			jugadores[i].setPartidasGanadas(1);
			apuestas[i] = apuestas[i] * 2;
			jugadores[i].setMonto(apuestas[i]);
			cout << "Jugador" << jugadores[i].getNombre() << " a GANADO!!" << endl;
			terminoPartida = true;
		}
		else if (jugadores[i].getPuntaje() > comparador) {
			cout << "Jugador" << jugadores[i].getNombre() << " obtuvo puntaje mayor a 21. Ha PERDIDO!!" << endl;
		}
		//falta cuando es menor.

	}
	return terminoPartida;
}






