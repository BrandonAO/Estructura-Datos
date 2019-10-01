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
#include "Admin.h"

bool billeteras[100]; //normal o con puntero para hacerlo dinamico, revisar.
Sistema::Sistema()
{
	max = 100;
	this->blackjack = new Blackjack();
	this->jugadores = new Jugador[max];
	this->administradores = new Admin[max];
	cantJugadores = 0;
	this->cantActualAdmin = 0;
	this->maxAdmin = 20;
	for (int i = 0; i < 100; i++) {
		billeteras[i] = false;
	}
		
}


//run sistem
void Sistema::iniciarSistema() {

	//lecturas

	leerArchivoCartas();
	cout << "------------- Se han agregado las cartas. -------------" << endl;
	blackjack->getMazo().imprimirCartas();
	cout << "------------- Se mezclaran las cartas. -------------" << endl;
	blackjack->getMazo().mezclarMazo();
	blackjack->getMazo().imprimirCartas();

	leerArchivoJugadores();
	/*
	for (int i = 0; i < cantJugadores; i++) {
		cout << "Nombre: " << jugadores[i].getNombre() << "   Id: " << jugadores[i].getIdBilletera() << endl;
	}
	for (int i = 0; i < 100; i++) {
		cout << "id: " << i + 1 << "   estado: " << billeteras[i] << endl;
	}
	*/
	leerArchivoAdmin();
	cout << "Se han agregado los administradores: " << endl;
	imprimirAdmin();
	//consulta de saldo.
	consultarSaldo();



}



//lectura admin

void Sistema::leerArchivoAdmin() {
	ifstream is("admin.txt");

	if (is) {
		string linea;

		// Mientras se pueda leer una linea del archivo ...
		int f = 0;

		while (getline(is, linea)) {
			stringstream ss(linea);

			// Obtenemos el rut y descartamos el ';'
			string rut;
			getline(ss, rut, ',');
			cout << "rut: " << rut << endl;


			// Obtenemos el id, este es el resto de la linea
			string id;
			getline(ss, id);
			cout << "id: " << id << endl;
			Admin* admin = new Admin(rut, id);
			agregarAdmin(*admin);
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
			Carta* carta = new Carta(valor, pinta);
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
			billeteras[idBilletera - 1] = true;

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
			return i + 1;
		}
	}
	return 0;

}
// consultar saldo de jugadores

void Sistema::consultarSaldo() {
	// Verifica que el administrador exista , y se hace la consulta de la idBilletera de los jugadores
	cout << "Iniciar cuenta administrador:" << endl;
	cout << "Ingresar rut admin:" << endl;
	string rutAdmin;
	cin >> rutAdmin;
	cout << "Ingresar clave admin;" << endl;
	string claveAdmin;
	cin >> claveAdmin;
	if (buscarAdmin(rutAdmin, claveAdmin) == true) {
		cout << "Sesion iniciada:" << endl;
		//lo busca por idBilltera, e imprime sus datos. y saldos
		cout << "Ingresar idBilletera a buscar:" << endl;
		int idBilletera;
		cin >> idBilletera;
		buscarJugador(idBilletera);

	}
	else {
		cout << "Intente otra vez:" << endl;
	}

}

void Sistema::agregarAdmin(Admin& admin) {
	if (cantActualAdmin < maxAdmin) {
		this->administradores[cantActualAdmin] = admin;
		cantActualAdmin++;

	}
}
void Sistema::imprimirAdmin()
{
	for (int i = 0; i < cantActualAdmin; i++) {
		cout << "Rut: " << administradores[i].getRut() << "   Id: " << administradores[i].getId() << endl;
	}
}

bool Sistema::buscarAdmin(string rut, string id)
{
	for (int i = 0; i < cantActualAdmin; i++) {
		if (administradores[i].getRut().compare(rut) == 0 && administradores[i].getId().compare(id) == 0) {
			cout << "Encontrado" << endl;
			return true;

		}
	}
	cout << "No encontrado" << endl;
	return false;
}

bool Sistema::buscarJugador(int idBilletera)
{

	for (int i = 0; i < cantJugadores; i++) {
		if (jugadores[i].getIdBilletera() == idBilletera) {
			cout << "Encontrado" << endl;
			cout << "Nombre: " << jugadores[i].getNombre() << " idBilletera: " << jugadores[i].getIdBilletera() << " Saldo disponible:" << jugadores[i].getMonto() << endl;
			return true;
		}
	}
	cout << "No encontrado" << endl;
	return false;

}

