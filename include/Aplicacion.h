
#ifndef _Aplicacion_
#define _Aplicacion_
#include <iostream>
#include <string>
#include "CampoMinas.h"
using namespace std;

/** \file Aplicacion.h
 * \brief Contiene la definicion de la clase Aplicacion
 *
 * AUTORES:

   DNI   45567904-M    Julian Nicolas Herrero
   DNI   74233276-V    Patricia Gallego Rodriguez

   El fichero Aplicacion.h contiene tanto la propia definicion de la clase, asi como la
   inclusion de las librerias necesarias y los prototipos de las funciones o metodos
   para su correcta ejecucion.
 */

/** \brief Clase Aplicacion:un puntero a la propia clase, un doble puntero a mina para crear el array de minas      un puntero a CampoMinas y 4 enteros que almacenan los valores del eje X, el eje Y, el numero de minas Bonus     y el numero de minas Estandar
 *
 * La clase Aplicacion contiene dos variables enteras dimx y dimy que almacenaran las dimensiones del campo de     minas, otras dos enteras numMinasBonus y numMinasEst que almacena el numero de minas Bonus y el de minas        Estandar correspondiente un puntero *pap estatico a la misma clase para asegurarnos que solo se crea un 	   objeto aplicacion, un doble puntero a Mina para crear un vector de punteros a minas, y un puntero a             CampoMinas para crear el campo de minas con las dimensiones de dimx y dimy.
  ..
 */

enum OpcionMenu{CONFIGURAR,JUGAR,SALIR};

class Aplicacion {
	protected:
		Aplicacion(int a=8,int b=2,int c=9);
		void crearCampoMinas();
		void crearArrayMinas();
		void liberarCampoMinas();
		void liberarArrayMinas();
	private:
		/** \brief Variable: pap que es un puntero a la propia clase, doble puntero a Mina para crear 			el arrayMinas, cm puntero a CampoMinas para crear el campo de minas, dimx es un entero con el 			tamaño del eje x del campo, dimy con el tamaño del eje y del campo, numMinasEst y numMinasBonus 		dos enteros con la cantidad de minas Estandar y minas Bonus respectivamente
		
		 */
		static Aplicacion *pap;
		Mina **arrayMinas;
		CampoMinas *cm;
		int dimx,dimy,numMinasEst,numMinasBonus;
	public:
		static Aplicacion* getInstancia();
		~Aplicacion();
		int getNumMinas() const;
		int getNumMinasBonus() const;
		int getNumMinasEst() const;
		int getDimX() const;
		int getDimY() const;
		Mina** getArrayMinas() const;
		CampoMinas* getCampoMinas() const;
		void setNumMinasBonus(int);
		void setNumMinasEst(int);
		void setDimX(int);
		void setDimY(int);
		void setArrayMinas(Mina**);
		void setCampoMinas(CampoMinas*);
		void run();
		OpcionMenu gestionarMenu();
		void configurar();
		int jugar();
};
#endif
