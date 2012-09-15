
#include "Casilla.h"
/** \file Casilla.cpp
 * \brief Contiene la definicion de los metodos de la clase Casilla.
 *
 * AUTORES:

   DNI   45567904-M    Julian Nicolas Herrero
   DNI   74233276-V    Patricia Gallego Rodriguez

   El fichero Casilla.cpp contiene la definicion de los metodos de la clase Casilla, asi como
   las posibles sobrecargas de operadores.
 */


/** \brief Constructor por defecto
 *
 * Constructor por defecto: Crea un objeto de la clase Casilla que por defecto esta CUBIERTA, el numero de minas
   que tiene alrededor es 0 y el puntero a Mina es igual a NULL.
 * \return Esta funcion al ser Constructor devuelve *this.
 */

Casilla::Casilla(){
	estado=CUBIERTA;
	numMinasAlrededor=0;
	m=NULL;
}


/** \brief Constructor de Copia
 *
 * Constructor de Copia: este constructor crea un nuevo objeto de tipo casilla a partir de otro que
   pasamos como parametro de entrada del constructor.
 * \param c de tipo Casilla pasado por referencia
 * \return Esta funcion al ser Constructor devuelve *this.
 */

Casilla::Casilla(const Casilla &ca){
	estado=ca.estado;
	numMinasAlrededor=ca.numMinasAlrededor;
	m=ca.m;
}


/** \brief Destructor de Casilla
 *
 * Destructor de Casilla: Esta funion destruye un objeto casilla liberando la posible memoria ocupada.
 * \param No tiene parametros de entrada salvo el propio objeto que la invoca.
 * \return Esta funcion al ser Destructor devuelve *this.
 */

Casilla::~Casilla(){
	estado=CUBIERTA;
	numMinasAlrededor=0;
	m=NULL;
}


/** \brief Funcion setDescubierta
 *
 * Funcion setDescubierta: esta funcion pone la variable estado con valor DESCUBIERTA.
 * \param No tiene parametros de entrada salvo el propio objeto que la invoca.
 * \return devuelve void.
 */

void Casilla::setDescubierta(){
	estado=DESCUBIERTA;
}


/** \brief Funcion getDescubierta
 *
 * Funcion getDescubierta: Esta funcion nos indica si el estado del objeto casilla que lo invoca esta
   o no DESCUBIERTA.
 * \param No tiene parametros de entrada salvo el propio objeto que la invoca.
 * \return Esta funcion devuelve true si la casilla estaba DESCUBIERTA, false en caso contrario.
 */

bool Casilla::getDescubierta() const{
	bool res;
	if (estado==DESCUBIERTA) res=true;
	else res=false;
return res;
}


/** \brief Funcion setMarcada
 *
 * Funcion setMarcada: esta funcion pone la variable estado con valor MARCADA.
 * \param No tiene parametros de entrada salvo el propio objeto que la invoca.
 * \return devuelve void.
 */

void Casilla::setMarcada(){
	estado=MARCADA;
}


/** \brief Funcion getMarcada
 *
 * Funcion getMarcada: Esta funcion nos indica si el estado del objeto casilla que lo invoca esta
   o no MARCADA.
 * \param No tiene parametros de entrada salvo el propio objeto que la invoca.
 * \return Esta funcion devuelve true si la casilla estaba MARCADA, false en caso contrario.
 */

bool Casilla::getMarcada() const{
	bool res;
	if (estado==MARCADA) res=true;
	else res=false;
return res;
}


/** \brief Sobrecarga del operador de salida <<
 *
 * Sobrecarga del operador de salida <<: Esta funcion la utilizamos para poder mostrar por la
   salida estandar con la funcion cout el estado de una casilla con el siguiente formato:
   *: casilla descubierta y con mina
   numero de minas de alrededor: casilla descubierta y sin mina.
   M: casilla marcada.
   (espacio en blanco): casilla cubierta.
 * \param o de tipo ostream por referencia.
 * \param c de tipo Casilla por referencia.
 * \return esta funcion devuelve una variable de tipo ostream.
 */

ostream& operator<<(ostream &o,const Casilla &c){
	if ((c.getMina()!=NULL)&&(c.getDescubierta())) o<<"*";
	else{
		if (c.getDescubierta()==true) o<<c.getNumMinasAlrededor();
		else{
			if (c.getMarcada()==true) o<<"M";
			else o<<" ";
		}
	}
return (o);
}


/** \brief Funcion getMina
 *
 * Funcion getMina: Esta funcion nos indica si la casilla que lo invoca contiene una mina o no.
 * \param No tiene parametros de entrada salvo el propio objeto que la invoca.
 * \return Esta funcion devuelve la referencia a Mina si la casilla contenia una mina y un puntero
    a NULL si la casilla no contenia una mina.
 */

Mina* Casilla::getMina() const{
return m;
}


/** \brief Funcion setMina
 *
 * Funcion setMina: esta funcion le da a la variable m del objeto casilla que lo invoca el valor de la
   direccion de memoria del objeto tipo Mina que pasamos como parametro de entrada por referencia.
 * \param mina de tipo Mina pasado por referencia.
 * \return devuelve true si todo ha funcionado segun lo esperado y false en caso contrario.
 */

bool Casilla::setMina(Mina& mina){
	bool res=true;
	m=&mina;
	if (m==NULL) res=false;
return res;
}


/** \brief Funcion getNumMinasAlrededor
 *
 * Funcion getNumMinasAlrededor: Esta funcion nos devuelve el valor de la variable numMinasAlrededor.
 * \param No tiene parametros de entrada salvo el propio objeto que la invoca.
 * \return Esta funcion devuelve el numero de minas que tiene la casilla a su alrededor.
 */

int Casilla::getNumMinasAlrededor() const{
return numMinasAlrededor;
}


/** \brief Funcion setNumMinasAlrededor
 *
 * Funcion setNumMinasAlrededor: Esta funcion cambia el valor de la variable numMinasAlrededor igualandolo
   al de la variable entera pasada como parametro de entrada.
 * \param nMinas de tipo entero.
 * \return devuelve void.
 */

void Casilla::setNumMinasAlrededor(int nMinas){
	numMinasAlrededor=nMinas;
}


/** \brief Funcion muestraDescubierta
 *
 * Funcion muestraDescubierta: Esta funcion hace que al imprimirse por pantalla el campo de minas todas las casillas
   aparezcan como si estuviesen descubiertas, apareciendo las minas en su lugar y el tipo de mina que es.
 * \param o de tipo ostream.
 * \return devuelve void.
 */

void Casilla::muestraDescubierta(ostream &o){
	if ((getMina()!=NULL)&&(getDescubierta())) o<<"*";
	else{
		if (getDescubierta()==true) o<<getNumMinasAlrededor();
		else{
			if(getMina()!=NULL)
				getMina()->imprimeSimbolo(o);
			else o<<" ";
		}
	}
}
