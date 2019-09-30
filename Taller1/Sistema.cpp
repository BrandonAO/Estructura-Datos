#include "Sistema.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <string>
using std::string;
using std::getline;

#include <sstream>
using std::stringstream;
using namespace std;
//libreria clases
#include "Carta.h"
#include "Mazo.h"
#include "Blackjack.h"
#include "Jugador.h"

bool billeteras[100]; //normal o con puntero para hacerlo dinamico, revisar.
Sistema::Sistema()
{
	max = 100;
	this->blackjack = new Blackjack();
	this->jugadores = new Jugador[max];
	cantJugadores = 0;
	for (int i = 0; i < 100; i++) {
		billeteras[i] = false;
	}

}


//run sistem
void Sistema::iniciarSistema() {

	//lecturas
	//leerArchivoAdmin();
	leerArchivoCartas();
	cout << "------------- Se han agregado las cartas. -------------" << endl;
	blackjack->getMazo().imprimirCartas();
	cout << "------------- Se mezclaran las cartas. -------------" << endl;
	blackjack->getMazo().mezclarMazo();
	blackjack->getMazo().imprimirCartas();
	leerArchivoJugadores();
	for (int i = 0; i < cantJugadores; i++) {
		cout << "Nombre: " << jugadores[i].getNombre() << "   Id: " << jugadores[i].getIdBilletera() << endl;
	}
	for (int i = 0; i < 100; i++) {
		cout << "id: " << i+1 << "   estado: " << billeteras[i] << endl;
	}
	

}

// vector admin
string admin[100][2];
int contAdmin = 0;
//lectura admin
void Sistema::leerArchivoAdmin() {
	ifstream is("admin.txt");

	if (is) {
		string linea;

		// Mientras se pueda leer una linea del archivo ...
		int f = 0;

		while (getline(is, linea)) {
			stringstream ss(linea);
			contAdmin++;

			contAdmin++;
			// Obtenemos el rut y descartamos el ';'
			string rut;
			getline(ss, rut, ',');
			cout << "rut: " << rut << endl;
			admin[f][0] = rut;

			// Obtenemos el id, este es el resto de la linea
			string id;
			getline(ss, id);
			cout << "id: " << id << endl;
			admin[f][1] = id;
			f++;
			cout << endl;
		}

		is.close();
	}

}
//lectura cartas
void Sistema::leerArchivoCartas() {
	ifstream is("cartas.txt");

	if (is) {
		string linea;

		// Mientras se pueda leer una linea del archivo ...
		while (getline(is, linea)) {
			stringstream ss(linea);

			// Obtenemos el valor y descartamos el ';'
			string valor;
			getline(ss, valor, ',');


			// Obtenemos el pinta, este es el resto de la linea
			string pinta;
			getline(ss, pinta);
			
			// Agregar carta al mazo
			Carta *carta = new Carta(valor, pinta);
			blackjack->getMazo().agregarCarta(*carta);


		}



		cout << endl;
	}

	is.close();
}

//leer archivo jugadores
void Sistema::leerArchivoJugadores() {
	ifstream is("jugadores.txt");

	if (is) {
		string linea;

		// Mientras se pueda leer una linea del archivo ...
		while (getline(is, linea)) {
			stringstream ss(linea);

			// Obtenemos el rut y descartamos el ','
			string rut;
			getline(ss, rut, ',');
			cout << "rut: " << rut << endl;

			// Obtenemos el nombre y descartamos el ','
			string nombre;
			getline(ss, nombre, ',');
			cout << "nombre: " << nombre << endl;
			// Obtenemos el idBilletera y descartamos el ','
			string numText;
			getline(ss, numText, ',');
			int idBilletera = stoi(numText);
			cout << "idBilletera: " << numText << endl;

			// Obtenemos el monto y descartamos el ','
			//pendiente castear a int

			getline(ss, numText, ',');
			int monto = stoi(numText);
			cout << "monto: " << monto << endl;

			// Obtenemos el partidasGanadas, es el resto de la linea
			
			getline(ss, numText);
			short int partidasGanadas = stoi(numText);
			cout << "partidas ganadas: " << partidasGanadas << endl;

			Jugador* jugador = new Jugador(nombre, rut, monto, idBilletera, partidasGanadas);
			this->agregarJugador(*jugador);
			billeteras[idBilletera-1] = true;

		}

		is.close();
	}

}

void Sistema::agregarJugador(Jugador& jug) {
	if (cantJugadores < max) {
		jugadores[cantJugadores] = jug;
		cantJugadores++;
	}
}

void Sistema::registrarJugador() {

	string nombre;
	cout << "Ingrese nombre: " << endl;
	cin >> nombre;

	cout << "Ingrese rut: " << endl;
	string rut;
	cin >> rut;

	int idBilletera = asignarBilletera();
	Jugador* jug = new Jugador(nombre, rut, idBilletera);
	agregarJugador(*jug);

}

int Sistema::asignarBilletera() {
	for (int i = 0; i < 100; i++) {
		if (billeteras[i] == false) {
			billeteras[i] = true;
			return i+1;
		}
	}
	return 0;
}

