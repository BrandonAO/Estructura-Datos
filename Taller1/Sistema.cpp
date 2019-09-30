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

Sistema::Sistema()
{
	blackjack = new Blackjack();
}

//run sistem
void Sistema::iniciarSistema() {

	//lecturas

	leerArchivoCartas();
	cout << "Se han agregado las cartas. " << endl;
	blackjack->getMazo().imprimirCartas();
	cout << "Se mezclaran las cartas. " << endl;
	blackjack->getMazo().mezclarMazo();
	blackjack->getMazo().imprimirCartas();
	leerArchivoAdmin();
	cout << "Se han agregado los administradores: " << endl;
	blackjack->imprimirAdmin();
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
			Admin  *admin = new Admin(rut, id);
			blackjack->agregarAdmin(*admin);
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
			//pendiente castear a int [listo]
			
			getline(ss, numText);
			short int partidasGanadas = stoi(numText);
			cout << "partidas ganadas: " << partidasGanadas << endl;

			Jugador* jugador = new Jugador(nombre, rut, monto, idBilletera, partidasGanadas);
			blackjack->agregarJugador(*jugador);

		}

		is.close();
	}

	
}
// consultar saldo de jugadores
void Sistema::consultarSaldo() {
	// Verifica que el administrador exista , y se hace la consulta de la idBilletera de los jugadores
	cout << "Iniciar cuenta administrador:" << endl;
	cout << "Ingresar rut admin:" << endl;
	string rutAdmin;
	cin >> rutAdmin;
	cout << "Ingresar id admin;" << endl;
	string idAdmin;
	cin >> idAdmin;
	if (blackjack->buscarAdmin(rutAdmin, idAdmin) == true) {
		cout << "Sesion iniciada:" << endl;
		//lo busca por idBilltera, e imprime sus datos. y saldos
		cout << "Ingresar idBilletera a buscar:" << endl;
		int idBilletera;
		cin >> idBilletera;
		blackjack->buscarJugador(idBilletera);

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
	if (blackjack->buscarAdmin(rutAdmin, idAdmin) == true) {
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







	


