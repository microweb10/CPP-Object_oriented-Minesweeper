
#ifndef _Mina_
#define _Mina_
#include <iostream>
#include <string>
using namespace std;

/** \file Mina.h
 * \brief Contiene la definicion de la clase Mina
 *
 * AUTORES:

   DNI   45567904-M    Julian Nicolas Herrero
   DNI   74233276-V    Patricia Gallego Rodriguez

   El fichero Mina.h contiene tanto la propia definicion de la clase, como los prototipos de las funciones o       metodos para su correcta ejecucion..
 */

/** \brief Clase Mina: una variable char (caracter)
 *
 * La clase Mina contiene una variable char con el simbolo que distingue de que tipo de mina se trata. Este        simbolo sera una B para las minas Bonus y una E para las Estandar
 */

class Mina {
	protected:
		/** \brief Variable de tipo char simbolo.
		 *
		 * Dicha variable contiene el simbolo correspondiente al tipo de mina
		   ( un espacio en blanco -> Mina   E -> MinaEstandar  B -> MinaBonus )
		 */
		char simbolo;
	public:
		Mina();
		Mina(const Mina&);
		virtual ~Mina();
		virtual int getPuntos() const=0;
		virtual void imprimeSimbolo(ostream&) const;
};

class MinaBonus: public Mina {
	private:
		/** \brief Variable de tipo numero entero.
		 *
		 * Dicha variable contiene los puntos de bonificacion de la MinaBonus que son 5.
		 */
		static int puntos;
	public:
		MinaBonus();
		MinaBonus(const MinaBonus&);
		~MinaBonus();
		int getPuntos() const;
};

class MinaEstandar: public Mina {
	private:
		/** \brief Variable de tipo numero entero.
		 *
		 * Dicha variable contiene los puntos de bonificacion de la MinaEstandar que son 1.
		 */
		static int puntos;
	public:
		MinaEstandar();
		MinaEstandar(const MinaEstandar&);
		~MinaEstandar();
		int getPuntos() const;
};
#endif
