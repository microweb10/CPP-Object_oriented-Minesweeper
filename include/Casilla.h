
#ifndef _Casilla_
#define _Casilla_
#include <iostream>
#include <string>
#include "Mina.h"
using namespace std;

/** \file Casilla.h
 * \brief Contiene la definicion de la clase Casilla
 *
 * AUTORES:

   DNI   45567904-M    Julian Nicolas Herrero
   DNI   74233276-V    Patricia Gallego Rodriguez

   El fichero Casilla.h contiene tanto la propia definicion de la clase, asi como la
   inclusion de las librerias necesarias y los prototipos de las funciones o metodos
   para su correcta ejecucion.
 */

/** \brief Clase Casilla: una variable bool
 *
 * La clase Casilla nos da información acerca de cada casilla, si tiene mina o no, en caso de no tenerla, el       numero de minas de alrededor de dicha casilla y el estado de la casilla
  */

enum EstadoCasilla{CUBIERTA,MARCADA,DESCUBIERTA};

class Casilla {
	friend ostream& operator<<(ostream&,const Casilla&);
	private:
		/** \brief Variables: estado de tipo EstadoCasilla que nos indicara si la casilla esta                          CUBIERTA, MARCADA o DESCUBIERTA, numMinasAlrededor con un entero que nos indica cuantas minas 			hay alrededor de una casilla y un puntero a Mina llamado m que contendrá la dirección de 			memoria de la mina relacionada con una casilla.
		 *
		 */
		EstadoCasilla estado;
		int numMinasAlrededor;
		Mina* m;
	public:
		Casilla();
		Casilla(const Casilla&);
		~Casilla();
		void setDescubierta();
		bool getDescubierta() const;
		void setMarcada();
		bool getMarcada() const;
		Mina* getMina() const;
		bool setMina(Mina&);
		int getNumMinasAlrededor() const;
		void setNumMinasAlrededor(int);
		void muestraDescubierta(ostream&);
};
#endif
