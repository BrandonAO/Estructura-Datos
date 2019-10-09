#pragma execution_character_set( "utf-8" )
#include "Sistema.h"
#include <iostream>
#include <Windows.h>
using std::cin;
using std::cout;
using std::endl;

#include <fstream>

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
#include <cstdlib>




Sistema::Sistema()
{
	max = 100;
	this->blackjack = new Blackjack();
	this->jugadores = new Jugador[max];
	this->administradores = new Admin[max];
	cantJugadores = 0;
	this->cantActualAdmin = 0;
	this->maxAdmin = 20;
	this->ultimaId = 0;

}


//run sistem
void Sistema::iniciarSistema() {

	//lecturas

	leerArchivoCartas();
	blackjack->getMazo().mezclarMazo();
	leerArchivoAdmin();
	leerArchivoJugadores();

	pausa();
	menuPrincipal();
}

// Lecturas
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


			// Obtenemos el id, este es el resto de la linea
			string id;
			getline(ss, id);
			Admin* admin = new Admin(rut, id);
			agregarAdmin(*admin);
			cout << endl;
		}

		is.close();
	}

}
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

			// Obtenemos el nombre y descartamos el ','
			string nombre;
			getline(ss, nombre, ',');
			// Obtenemos el idBilletera y descartamos el ','
			string numText;
			getline(ss, numText, ',');
			int idBilletera = stoi(numText);

			if (ultimaId < idBilletera) {
				ultimaId = idBilletera;
			}

			// Obtenemos el monto y descartamos el ','
			//pendiente castear a int

			getline(ss, numText, ',');
			int monto = stoi(numText);
			// Obtenemos el partidasGanadas, es el resto de la linea

			getline(ss, numText);
			short int partidasGanadas = stoi(numText);

			Jugador* jugador = new Jugador(nombre, rut, monto, idBilletera, partidasGanadas);
			this->agregarJugador(*jugador);

		}

		is.close();
	}

}


// menu principal
void Sistema::menuPrincipal() {

	bool bandera = false;
	char tecla;

	do
	{
		system("cls");
		cin.clear();
		cout << ".:::::::::: BLACKJACK ::::::::::." << endl;
		cout << "-----------" << endl << endl;
		cout << "\t1 .- Iniciar partida " << endl;
		cout << "\t2 .- Jugadores On-fire" << endl;
		cout << "\t3 .- Configuracion " << endl;
		cout << "\t4 .- Salir " << endl << endl;
		cout << "Elije una opcion: ";

		cin >> tecla;

		switch (tecla)
		{
		case '1':
			system("cls");
			cout << "Has elegido opcion 1.\n";
			pausa();
			system("cls");
			menuPrincipalIniciarPartida();
			pausa();
			break;

		case '2':
			system("cls");
			cout << "Has elegido opcion 2.\n";
			pausa();
			system("cls");
			jugadoresOnFire();
			pausa();

			break;

		case '3':
			system("cls");
			cout << "Has elegido opcion 3.\n";
			menuPrincipalConfiguracion();
			pausa();
			break;

		case '4':
			system("cls");
			cout << "Has elegido opcion salir 4.\n";
			pausa();
			bandera = true;
			break;

		default:
			system("cls");
			cout << "Opcion no valida.\a\n";
			pausa();
			break;
		}
	} while (bandera != true);


}


// pausa para el menu
void Sistema::pausa()
{
	system("pause");
}
// menu 2 iniciar partida
void Sistema::menuPrincipalIniciarPartida() {

	bool bandera = false;
	char tecla;

	do
	{
		system("cls");
		cin.clear();
		cout << ".:::::::::: BLACKJACK  ::::::::::." << endl;
		cout << "-----------> Iniciar Partida" << endl << endl;
		cout << "\t1 .- Jugar " << endl;
		cout << "\t2 .- Agregar jugador" << endl;
		cout << "\t3 .- Eliminar jugador " << endl;
		cout << "\t4 .- Terminar partida " << endl;
		cout << "\t5 .- Salir " << endl << endl;
		cout << "Elije una opcion: ";

		cin >> tecla;

		switch (tecla)
		{
		case '1':
			system("cls");
			cout << "Has elegido opcion 1.\n";
			blackjack->partida();
			ordenarJugadores(0, cantJugadores - 1);
			escrituraArchivoJugadores();

			pausa();
			break;

		case '2':
			system("cls");
			cout << "Has elegido opcion 2.\n";
			agregarJugadorMesa();
			pausa();
			break;

		case '3':
			system("cls");
			cout << "Has elegido opcion 3.\n";
			eliminarJugadorMesa();
			break;

		case '4':
			system("cls");
			cout << "Has elegido opcion 4.\n";
			terminarPartida();
			pausa();
			break;

		case '5':
			cout << "Has elegido opcion salir.\n";
			bandera = true;
			break;

		default:
			system("cls");
			cout << "Opcion no valida.\a\n";
			pausa();
			break;
		}
	} while (bandera != true);


}

// menu 3 configuracion
void Sistema::menuPrincipalConfiguracion() {

	cout << "Iniciar cuenta administrador:" << endl;
	cout << "Ingresar rut admin:" << endl;
	string rutAdmin = "";
	getline(cin, rutAdmin);
	cout << "Ingresar contraseña;" << endl;
	string contraseña = "";
	getline(cin, contraseña);
	system("cls");
	if (!buscarAdmin(rutAdmin, contraseña)) {
		cout << "* Se ha ingresado un rut o contraseña incorrecta." << endl;
		return;
	}

	bool bandera = false;
	char tecla;

	do
	{
		system("cls");
		cin.clear();
		cout << ".:::::::::: BLACKJACK  ::::::::::." << endl;
		cout << "-----------> Configuracion" << endl << endl;
		cout << "\t1 .- Cargar saldo a la billetera electronica " << endl;
		cout << "\t2 .- Consultar saldo" << endl;
		cout << "\t3 .- Registrar jugador " << endl;
		cout << "\t4 .- Editar jugador " << endl;
		cout << "\t4 .- Salir " << endl << endl;
		cout << "Elije una opcion: ";

		cin >> tecla;

		switch (tecla)
		{
		case '1':
			system("cls");
			cout << "Has elegido opcion 1.\n";
			CargarSaldo();
			pausa();
			break;

		case '2':
			system("cls");
			cout << "Has elegido opcion 2.\n";
			consultarSaldo();
			pausa();
			break;

		case '3':
			system("cls");
			cout << "Has elegido opcion 3.\n";
			registrarJugador();
			pausa();
			break;

		case '4':
			cout << "Has elegido opcion 4.\n";
			editarJugador();
			pausa();
			break;

		case '5':
			cout << "Has elegido opcion salir.\n";
			bandera = true;
			break;

		default:
			system("cls");
			cout << "Opcion no valida.\a\n";
			pausa();
			break;
		}
	} while (bandera != true);


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
	getline(cin, nombre);

	cout << "Ingrese rut: " << endl;
	string rut;
	getline(cin, rut);

	Jugador* jug = new Jugador(nombre, rut, ultimaId);
	ultimaId++;
	agregarJugador(*jug);
	escrituraArchivoJugadores();

}

// consultar saldo de jugadores
void Sistema::consultarSaldo() {
	//lo busca por idBilltera, e imprime sus datos. y saldos
	cout << "Ingresar idBilletera a buscar:" << endl;
	int idBilletera;
	cin >> idBilletera;
	buscarJugador(idBilletera);
}

void Sistema::agregarJugadorMesa()
{
	string nombre;
	string rut;
	cout << "Ingrese el nombre del jugador:" << endl;
	getline(cin, nombre);

	cout << "Ingrese el rut del jugador:" << endl;
	
	getline(cin, rut);

	cout << "Ingrese la id de la billetera del jugador:" << endl;
	int idBilletera;
	cin >> idBilletera;
	for (int i = 0; i < cantJugadores; i++) {
		if (jugadores[i].getNombre().compare(nombre) == 0 && jugadores[i].getRut().compare(rut) == 0 && jugadores[i].getIdBilletera() == idBilletera) {
			if (blackjack->agregarJugador(jugadores[i]) == true) {
				cout << "El jugador " << jugadores[i].getNombre() << " se ha ingresado a la mesa." << endl;
				pausa();
				return;
			}

		}
	}
	cout << "El jugador " << nombre << " no se ha encontrado." << endl;
	pausa();
}
// Cargar saldo a a la billetera
void Sistema::CargarSaldo() {
	// Verifica que el administrador exista , y se hace la consulta de la idBilletera de los jugadores
	cout << "Sesion iniciada:" << endl;
	//lo busca por idBilltera, luego pregunta cuanto saldo hay que cargar
	cout << "Ingresar idBilletera a buscar:" << endl;
	int idBilletera;
	cin >> idBilletera;
	cout << "Ingresar saldo a cargar [$1.000 - $100.000]:" << endl;
	int saldo;
	cin >> saldo;
	if (saldo >= 1000 && saldo < 100000) {
		//se carga el saldo ingresado por pantalla.
		buscarJugadorSaldo(idBilletera, saldo);
	}

}

// se agrega administrador a la lista
void Sistema::agregarAdmin(Admin& admin) {
	if (cantActualAdmin < maxAdmin) {
		this->administradores[cantActualAdmin] = admin;
		cantActualAdmin++;

	}
}
//imprime los administradores registrados en el sistema
void Sistema::imprimirAdmin()
{
	for (int i = 0; i < cantActualAdmin; i++) {
		cout << "Rut: " << administradores[i].getRut() << "   Id: " << administradores[i].getId() << endl;
	}
}
//busca administrador por rut e id
bool Sistema::buscarAdmin(string rut, string contraseña)
{
	for (int i = 0; i < cantActualAdmin; i++) {
		if (administradores[i].getRut().compare(rut) == 0 && administradores[i].getId().compare(contraseña) == 0) {
			cout << "Encontrado" << endl;
			return true;

		}
	}
	cout << "No encontrado" << endl;
	return false;
}

//buscar jugador por idBilletera retorna true si lo encuentra
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
//busca jugador y agrega saldo a su billetra electronica
bool Sistema::buscarJugadorSaldo(int idBilletera, int saldo)
{

	for (int i = 0; i < cantJugadores; i++) {
		if (jugadores[i].getIdBilletera() == idBilletera) {
			cout << "Encontrado" << endl;
			cout << "Nombre: " << jugadores[i].getNombre() << " idBilletera: " << jugadores[i].getIdBilletera() << " Saldo Actual:" << jugadores[i].getMonto() << endl;
			cout << " Saldo anterior:" << jugadores[i].getMonto() << endl;
			int nuevoSaldo = jugadores[i].getMonto() + saldo;
			jugadores[i].setMonto(nuevoSaldo);
			cout << " Nuevo Saldo:" << jugadores[i].getMonto() << endl;
			return true;
		}
	}
	cout << "No encontrado" << endl;
	return false;

}
//edita el nombre del jugador buscado por rut
void Sistema::editarJugador() {
	cout << "Editar jugador" << endl;
	cout << "Ingresar rut jugador:" << endl;
	string rutJugador;
	cin >> rutJugador;
	cout << "Ingresar nuevo nombre para el jugador:" << endl;
	string nombre;
	getline(cin, nombre);
	buscarJugadorEditar(rutJugador, nombre);
	escrituraArchivoJugadores();
}
//busca por rut y modifica el nombre del jugador
bool Sistema::buscarJugadorEditar(string rut, string nombre)
{
	for (int i = 0; i < cantJugadores; i++) {
		if (jugadores[i].getNombre().compare(nombre) == 0) {
			cout << "Encontrado" << endl;
			cout << "Nombre actual: " << jugadores[i].getNombre() << endl;
			jugadores[i].setNombre(nombre);
			cout << "Nuevo nombre:: " << jugadores[i].getNombre() << endl;
			return true;
		}
	}
	cout << "No encontrado" << endl;
	return false;

}

// elimina jugador de la mesa
void Sistema::eliminarJugadorMesa() {
	if (blackjack->getCantActual() == 1) {
		cout << "Como usted es el unico jugador, debe seleccionar la opcion 4 (Terminar Partida) para retirarse." << endl;
		return;
	}
	cout << "Eliminar jugador" << endl;
	cout << "Ingresar rut jugador:" << endl;
	string rutJugador;
	cin >> rutJugador;
	blackjack->eliminarJugador(rutJugador);
}

void Sistema::terminarPartida()
{

	blackjack->eliminarTodosJugadores();

}

//ordenar jugadores por partidas ganadas

void Sistema::ordenarJugadores(int low, int high)
{
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		ordenarJugadores(low, mid);
		ordenarJugadores(mid + 1, high);
		merge(low, high, mid);
	}
}

void Sistema::merge(int low, int high, int mid) {
	int i, j, k;
	Jugador c[20];
	i = low;
	k = low;
	j = mid + 1;
	while (i <= mid && j <= high) {
		if (jugadores[i].getPartidasGanadas() > jugadores[j].getPartidasGanadas()) {
			c[k] = jugadores[i];
			k++;
			i++;
		}
		else {
			c[k] = jugadores[j];
			k++;
			j++;
		}
	}
	while (i <= mid) {
		c[k] = jugadores[i];
		k++;
		i++;
	}
	while (j <= high) {
		c[k] = jugadores[j];
		k++;
		j++;
	}
	for (i = low; i < k; i++) {
		jugadores[i] = c[i];
	}

}

// mejores 10 jugadores
void Sistema::jugadoresOnFire() {
	ordenarJugadores(0, cantJugadores - 1);
	escrituraArchivoJugadores();
	for (int i = 0; i < 10; i++) {
		cout << "Rut: " << jugadores[i].getRut() << "   Nombre: " << jugadores[i].getNombre() << "  IdBilletera: " << jugadores[i].getIdBilletera() << "  Monto: " << jugadores[i].getMonto() << "  Partidas Ganadas: " << jugadores[i].getPartidasGanadas() << endl;
	}

}

// reescritura archivo jugadores.
void Sistema::escrituraArchivoJugadores()
{
	ofstream archivo;  // objeto de la clase ofstream
	archivo.open("jugadores.txt", ios::out);
	for (int i = 0; i < cantJugadores; i++) {
		archivo << jugadores[i].getRut() << "," << jugadores[i].getNombre() << "," << jugadores[i].getIdBilletera() << "," << jugadores[i].getMonto() << "," << jugadores[i].getPartidasGanadas() << endl;
	}
	archivo.close();
}


