#include "Carta.h"

Carta::Carta()
{

	valor = '0';
	pinta = "";
}

Carta::Carta(char _valor, string _pinta)
{
	valor = _valor;
	pinta = _pinta;
}
