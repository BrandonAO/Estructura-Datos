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
//librearia clases
#include "Carta.h"
#include "Mazo.h"
#include "Blackjack.h"
#include "Jugador.h"

// vector admin
string admin[100][2];
int contAdmin = 0;
//lectura admin
void leerArchivoAdmin() {
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
void leerArchivoCartas() {
	ifstream is("cartas.txt");

	if (is) {
		string linea;

		// Mientras se pueda leer una linea del archivo ...
		while (getline(is, linea)) {
			stringstream ss(linea);

			// Obtenemos el valor y descartamos el ';'
			string valor;
			getline(ss, valor, ',');
			cout << "valor: " << valor << endl;

			// Obtenemos el pinta, este es el resto de la linea
			string pinta;
			getline(ss, pinta);
			cout << "pinta: " << pinta << endl;
			Carta carta(valor, pinta);
			Mazo* mazo = new Mazo();
			mazo->agregarCarta(carta);
		}



			cout << endl;
		}

		is.close();
	}

}
//leer archivo jugadores
void leerArchivoJugadores() {
	ifstream is("jugadores.txt");

	if (is) {
		string linea;

		// Mientras se pueda leer una linea del archivo ...
		while (getline(is, linea)) {
			stringstream ss(linea);

			// Obtenemos el rut y descartamos el ';'
			string rut;
			getline(ss, rut, ',');
			cout << "rut: " << rut << endl;

			// Obtenemos el nombre y descartamos el ';'
			string nombre;
			getline(ss, nombre, ',');
			cout << "nombre: " << nombre << endl;
			// Obtenemos el idBilletera y descartamos el ';'
			string idBilletera;
			getline(ss, idBilletera, ',');
			cout << "idBilletera: " << idBilletera << endl;

			// Obtenemos el monto y descartamos el ';'
			//pendiente castear a int
			string monto;
			getline(ss, monto, ',');
			cout << "monto: " << monto << endl;

			// Obtenemos el partidasGanadas, es el resto de la linea
			//pendiente castear a int
			string partidasGanadas;
			getline(ss, partidasGanadas);
			cout << "partidas ganadas: " << partidasGanadas << endl;

			cout << endl;
		}

		is.close();
	}

}



int main()
{
	std::cout << "Hello World!\n";
	leerArchivoAdmin();
	leerArchivoCartas();
	leerArchivoJugadores();
	cout << "contador de linear administradores: " << contAdmin << endl;
	for (int i = 0; i < contAdmin; i++) {
		for (int j = 0; j < 2;j++) {
			cout << "rut, id: " << admin[i][j] << endl;
		

		}

	}
}