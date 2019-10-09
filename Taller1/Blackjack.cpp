#include "Blackjack.h"
#include "Croupier.h"
#include "Admin.h"
#include "Jugador.h"
#include <iostream>
#include <Windows.h>
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
bool Blackjack::eliminarTodosJugadores()
{
	Jugador j = Jugador();
	for (int i = 0; i < cantActual; i++) {
		jugadores[i] = j;
		cantActual--;

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
	if (cantActual == 0) {
		cout << "* Debe agregar jugadores para iniciar una ronda." << endl;
		return;
	}

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
		if (jugadores[i].getPuntaje() == 21) {
			jugadores[i].setPartidasGanadas(1);
			apuestas[i] = apuestas[i] * 2;
			jugadores[i].setMonto(apuestas[i]);
			cout << "Jugador " << jugadores[i].getNombre() << " a GANADO!!" << endl;
		}
	}
	

	//reparte al croupier
	bool as = false;
	bool cartasMano = croupier.ingresarCarta(mazo.sacarCarta());
	if (croupier.getPuntaje() == 11) {
		as = true;
	}
	imprimirCartas();


	//sigue partida
	for (int i = 0; i < cantActual; i++) {
		int opcion = 0;
		if (!as) {
			cout << "Jugador" << jugadores[i].getNombre() << " ¿Quiere rendirse? SI[1] NO[0]" << endl;

			cin >> opcion;
			if (opcion == 1) {
				//rendirse
				jugadores[i].setMonto(apuestas[i] / 2);
				jugadores[i].setRetiroRonda(true);
				break;
			}
		}
		else {
			cout << "* El Croupier tiene un AS. Ningun jugador puede rendir." << endl;
		}

		if (!jugadores[i].getRetiroRonda()) {
			cout << "Jugador" << jugadores[i].getNombre() << " Sacar carta [1], No sacar carta [2] " << endl;
			cin >> opcion;


			if (opcion == 1) {
				//sacar carta
				bool masCartas = true;
				while (masCartas) {
					imprimirCartas();
					cout << "Jugador " << jugadores[i].getNombre() << " ¿sacar carta? Si [1], No [2]  " << endl;
					int opcion2 = 0;
					cin >> opcion2;
					if (opcion2 == 1) {
						cartasMano = jugadores[i].ingresarCarta(mazo.sacarCarta());
						verificarGanador(21, true);
					}
					if (opcion2 == 2) {
						masCartas = false;
						break;
					}

				}


			}
		}

	}
	//sacar cartas croupier > 16


	while (croupier.getPuntaje() < 16) {
		bool cartasMano = croupier.ingresarCarta(mazo.sacarCarta());
		imprimirCartas();
	}

	verificarGanador(croupier.getPuntaje(), false);

}

void Blackjack::imprimirCartas() {
	system("cls");
	Carta c = mazo.sacarCarta();
	string v = c.getValor();
	string pinta = c.getPinta();
	
	for (int i = 0; i < cantActual; i++) {
		if (!jugadores[i].getRetiroRonda()) {
			cout << "Jugador " << jugadores[i].getNombre() << " sus cartas: " << endl;
			for (int i = 0; i < jugadores[i].getCartasActual();i++) {
				cout << v << pinta << ", " ;
			}
		}
		cout << "" << endl;
	}

	
	cout << "Croupier sus cartas: " << endl;
	for (int i = 0; i < jugadores[i].getCartasActual(); i++) {
			cout << v << pinta << ", ";
	}
	cout << "" << endl;

}


bool Blackjack::verificarGanador(int comparador, bool forma)
{
	bool terminoPartida = false;


	if (!forma) {
		if (croupier.getPuntaje() > 21) {
			cout << "Croupier a PERDIDO!!. Todos ganan." << endl;
			for (int i = 0; i < cantActual; i++) {
				if (!jugadores[i].getRetiroRonda()) {
					jugadores[i].setPartidasGanadas(1);
					apuestas[i] = apuestas[i] * 2;
					jugadores[i].setMonto(apuestas[i]);
					cout << "Jugador" << jugadores[i].getNombre() << " a GANADO!!" << endl;
				}

			}
			return true;
		}
		for (int i = 0; i < cantActual; i++) {
			if (!jugadores[i].getRetiroRonda()) {
				if (jugadores[i].getPuntaje() > comparador) {
					jugadores[i].setPartidasGanadas(1);
					apuestas[i] = apuestas[i] * 2;
					jugadores[i].setMonto(apuestas[i]);
					cout << "Jugador" << jugadores[i].getNombre() << " obtuvo puntaje igual al croupier. a GANADO!!" << endl;
					terminoPartida = true;
				}
				if (jugadores[i].getPuntaje() == comparador) {
					jugadores[i].setMonto(apuestas[i] / 2);
					jugadores[i].setRetiroRonda(true);
					cout << "Jugador" << jugadores[i].getNombre() << " obtuvo puntaje mayor a 21. Ha EMPATADO!!" << endl;
				}
				if (jugadores[i].getPuntaje() < comparador) {
					cout << "Jugador" << jugadores[i].getNombre() << " obtuvo puntaje menor a 21. Ha PERDIDO!!" << endl;
				}
				//falta cuando es menor.
			}

		}
	}
	else { //cartas adicionales

		for (int i = 0; i < cantActual; i++) {
			if (!jugadores[i].getRetiroRonda()) {
				if (jugadores[i].getPuntaje() > 21) {
					cout << "Jugador" << jugadores[i].getNombre() << " obtuvo puntaje mayor a 21. Ha PERDIDO!!" << endl;
					jugadores[i].setRetiroRonda(true);
				}
			}
		}
	}
	return terminoPartida;
}

int Blackjack::getCantActual()
{
	return cantActual;
}






