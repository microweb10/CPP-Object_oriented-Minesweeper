
#ifndef _Coordenada_
#define _Coordenada_
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

/** \file Coordenada.h
 * \brief Contiene la definicion de la clase Coordenada
 *
 * AUTORES:

   DNI   45567904-M    Julian Nicolas Herrero
   DNI   74233276-V    Patricia Gallego Rodriguez

   El fichero Coordenada.h contiene tanto la propia definicion de la clase, asi como la
   inclusion de las librerias necesarias y los prototipos de las funciones o metodos
   para su correcta ejecucion.
 */

/** \brief Clase Coordenada: Bidimensional, dos valores enteros (uno para x, otro para y)
 *
 * La clase coordenada contiene dos variables enteras donde se guardan los valores de las
   diferentes coordenadas x e y declaradas como variables privadas de la propia clase,
   dispone de constructor, destructor, constructor de copia, funciones get y set para cada
   variable (x e y) y las funciones amigas necesarias para los operadores de entrada, salida.
  */

class Coordenada {
	friend ostream& operator<<(ostream &,const Coordenada &);
	friend istream& operator>>(istream &,Coordenada &);
	private:
		/** \brief Variables de tipo entero CoordX  y CoordY.
		 *
		 * En dichas variables enteras CoordX y CoordY se almacenara el valor de esa
		   parte de la coordenada de manera que una coordenada se compone de un valor
		   (numero entero) x, y exactamente igual (numero entero) para la y.
		 */
		int coordX,coordY;
	public:
		Coordenada(){coordX=-1;coordY=-1;}
		Coordenada(int,int);
		Coordenada(const Coordenada &);
		Coordenada &operator=(const Coordenada &);
		~Coordenada();
		int getCoordX() const;
		bool setCoordX(int);
		int getCoordY() const;
		bool setCoordY(int);
		static Coordenada getCoordenadaAleatoria(int,int);
		bool operator!=(const Coordenada &);
};
#endif
