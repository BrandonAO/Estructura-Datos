#include "Carta.h"

Carta::Carta()
{
	//falta inicializar pinta

	valor = "";
}

Carta::Carta(string _valor, char _pinta)
{
	valor = _valor;
	pinta = _pinta;
}
