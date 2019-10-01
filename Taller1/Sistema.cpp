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
#include <cstdlib>

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
// Cargar saldo a a la billetera
void Sistema::CargarSaldo() {
	// Verifica que el administrador exista , y se hace la consulta de la idBilletera de los jugadores
	cout << "Iniciar cuenta administrador:" << endl;
	cout << "Ingresar rut admin:" << endl;
	string rutAdmin;
	cin >> rutAdmin;
	cout << "Ingresar id admin;" << endl;
	string idAdmin;
	cin >> idAdmin;
	if (buscarAdmin(rutAdmin, idAdmin) == true) {
		cout << "Sesion iniciada:" << endl;
		//lo busca por idBilltera, luego pregunta cuanto saldo hay que cargar
		cout << "Ingresar idBilletera a buscar:" << endl;
		int idBilletera;
		cin >> idBilletera;
		cout << "Ingresar saldo a cargar [$1000 - 100000]:" << endl;
		int saldo;
		cin >> saldo;
		if (saldo >=  1000 && saldo < 100000) {
			//se carga el saldo ingresado por pantalla.
			buscarJugadorSaldo(idBilletera, saldo);
		}
		
	}
	else {
		cout << "Intente otra vez:" << endl;
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
			cout << "Taller 1: BLACKJACK" << endl;
			cout << "-----------" << endl << endl;
			cout << "\t1 .- Iniciar partida " << endl;
			cout << "\t2 .- Jugadores On-fire" << endl;
			cout << "\t3 .- Configuracion " << endl;
			cout << "\t4 .- Editar Jugador " << endl;
			cout << "\t5 .- Salir " << endl << endl;
			cout << "Elije una opcion: ";

			cin >> tecla;

			switch (tecla)
			{
			case '1':
				system("cls");
				cout << "Has elejido opcion 1.\n";
				menuPrincipalIniciarPartida();
				pausa();
				break;

			case '2':
				system("cls");
				cout << "Has elejido opcion 2.\n";
				pausa();
				break;

			case '3':
				system("cls");
				cout << "Has elejido opcion 3.\n";
				menuPrincipalConfiguracion();
				pausa();
				break;

			case '4':
				system("cls");
				cout << "Has elejido opcion 4.\n";
				pausa();
				break;

			case '5':
				cout << "Has elejido opcion salir.\n";
				bandera = true;
				//exit(1);
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
	cout << "Pulsa una tecla para continuar...";
	getwchar();
	getwchar();
}
// menu 2 iniciar partida
void Sistema::menuPrincipalIniciarPartida() {

	bool bandera = false;
	char tecla;

	do
	{
		system("cls");
		cin.clear();
		cout << "Taller 1: BLACKJACK ---> Iniciar Partida" << endl;
		cout << "-----------" << endl << endl;
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
			cout << "Has elejido opcion 1.\n";
			pausa();
			break;

		case '2':
			system("cls");
			cout << "Has elejido opcion 2.\n";
			pausa();
			break;

		case '3':
			system("cls");
			cout << "Has elejido opcion 3.\n";
			pausa();
			break;

		case '4':
			system("cls");
			cout << "Has elejido opcion 4.\n";
			pausa();
			break;

		case '5':
			cout << "Has elejido opcion salir.\n";
			bandera = true;
			//exit(1);
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

	bool bandera = false;
	char tecla;

	do
	{
		system("cls");
		cin.clear();
		cout << "Taller 1: BLACKJACK ---> Configuracion" << endl;
		cout << "-----------" << endl << endl;
		cout << "\t1 .- Cargar saldo a la billetera electronica " << endl;
		cout << "\t2 .- Consultar saldo" << endl;
		cout << "\t3 .- Registrar jugador " << endl;
		cout << "\t4 .- Salir " << endl << endl;
		cout << "Elije una opcion: ";

		cin >> tecla;

		switch (tecla)
		{
		case '1':
			system("cls");
			cout << "Has elejido opcion 1.\n";
			pausa();
			break;

		case '2':
			system("cls");
			cout << "Has elejido opcion 2.\n";
			pausa();
			break;

		case '3':
			system("cls");
			cout << "Has elejido opcion 3.\n";
			pausa();
			break;

		case '4':
			cout << "Has elejido opcion salir.\n";
			bandera = true;
			//exit(1);
			break;

		default:
			system("cls");
			cout << "Opcion no valida.\a\n";
			pausa();
			break;
		}
	} while (bandera != true);


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
	cout << "Ingresar n uevo nombre para el jugador:" << endl;
	string nombre;
	cin >> nombre;
	buscarJugadorEditar(rutJugador, nombre);
	}
//busca por rut y modifica el nombre del jugador
bool Sistema::buscarJugadorEditar(string rut, string nombre)
{
	for (int i = 0; i < cantJugadores; i++) {
		if (jugadores[i].getNombre().compare(nombre)==0) {
			cout << "Encontrado" << endl;
			cout << "Nombre actual: " << jugadores[i].getNombre()<< endl;
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
	cout << "Eliminar jugador" << endl;
	cout << "Ingresar rut jugador:" << endl;
	string rutJugador;
	cin >> rutJugador;
	eliminarJugador(rutJugador);
}
//metodo que elimina al jugador segun rut
bool Sistema::eliminarJugador(string rut)
{
	for (int i = 0; i < cantJugadores; i++) {
		if (jugadores[i].getRut().compare(rut) == 0) {
			cout << "Encontrado" << endl;
			cout << "Jugador rut: " << jugadores[i].getRut() << endl;
			//aca se hace la eliminacion
			
			return true;
		}
	}
	cout << "No encontrado" << endl;
	return false;

}



