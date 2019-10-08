#include <iostream>
#include <Windows.h>


//libreria clases
#include "Sistema.h"


int main()
{
	
	SetConsoleOutputCP(CP_UTF8); 
	Sistema* sistema = new Sistema();
	sistema->iniciarSistema();


};