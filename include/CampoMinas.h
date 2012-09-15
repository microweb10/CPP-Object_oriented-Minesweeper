
#ifndef _CampoMinas_
#define _CampoMinas_
#include <iostream>
#include <string>
#include "Coordenada.h"
#include "Casilla.h"
using namespace std;

/** \file CampoMinas.h
 * \brief Contiene la definicion de la clase CampoMinas
 *
 * AUTORES:

   DNI   45567904-M    Julian Nicolas Herrero
   DNI   74233276-V    Patricia Gallego Rodriguez

   El fichero CampoMinas.h contiene tanto la propia definicion de la clase, asi como la
   inclusion de las librerias necesarias y los prototipos de las funciones o metodos
   para su correcta ejecucion.
 */

/** \brief Clase CampoMinas:Bidimensional, dos valores enteros (uno para x, otro para y), y una variable
     casilla para el Campo de Minas
 *
 * La clase CampoMinas contiene dos variables enteras que almacenaran las dimensiones del campo de minas
   y un doble puntero de tipo Casilla con el que crearemos el campo de minas a partir de las dimensiones
   almacenadas en dimx y dimy. Tiene un constructor por defecto, un constructor de copia, destructor,
   funciones getDimX y getDimY que nos verificaran el valor de las dimensiones, una función que devuel-
   ve bool en la que comprobaremos si una casilla está previamente descubierta al intentar descubrirla y una       función que devueve bool en la que comprobaremos si una casilla está previamente marcada o descubierta al       intentar marcarla.
  */


const int MAX_INTENTOS=10;
class Aplicacion;

class CampoMinas {
	friend ostream& operator<<(ostream&,const CampoMinas&);
	private:
		/** \brief Variables: dimx y dimy de tipo entero y casilla que es un doble puntero a Casilla
		 *
		 * En dimx guardaremos la dimension horizontal del campo de minas y en dimy la dimension
		   vertical del mismo campo de minas. Con casilla creamos el campo de minas en si.
		 */
		int dimx;
		int dimy;
		Casilla **casilla;
	public:
		CampoMinas(int=9,int=9);
		CampoMinas(const CampoMinas&);
		~CampoMinas();
		int getDimX() const;
		int getDimY() const;
		Casilla&  getCasilla(const Coordenada&);
		bool hasMina(const Coordenada&);
		bool marcaCasilla(const Coordenada&);
		bool descubreCasilla(const Coordenada&);
		bool colocaMinas(Mina**);
		int calculaPuntos();
		void setNumMinasAlrededorCasilla(Coordenada&);
};
#endif
