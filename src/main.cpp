
#include "Aplicacion.h"
/** \file main.cpp
 * \brief Contiene el programa principal
 *
 * AUTORES:

   DNI   45567904-M    Julian Nicolas Herrero
   DNI   74233276-V    Patricia Gallego Rodriguez

   El fichero main.cpp funciona como un punto de entrada al juego.
 */

int main(){
	Aplicacion *a;
	a=Aplicacion::getInstancia();
	a->run();
return(0);
}

