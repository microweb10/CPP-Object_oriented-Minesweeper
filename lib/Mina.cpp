#include "Mina.h"
/** \file Mina.cpp
 * \brief Contiene la definicion de los metodos de las clases Mina, MinaBonus y MinaEstandar.
 *
 * AUTORES:

   DNI   45567904-M    Julian Nicolas Herrero
   DNI   74233276-V    Patricia Gallego Rodriguez

   El fichero Mina.cpp contiene la definicion de los metodos de las clases Mina, MinaBonus y MinaEstandar,
   asi como las posibles sobrecargas de operadores.
 */


// ATRIBUTOS DE LA CLASE MINA

/** \brief Constructor por defecto
 *
 * Constructor por defecto: Crea un objeto de la clase Mina
 * \return Esta funcion al ser Constructor devuelve *this.
 */
 

Mina::Mina(){}


/** \brief Constructor de Copia
 *
 * Constructor de Copia: este constructor crea una nueva mina a partir de otra que
   pasamos como parametro de entrada del constructor, igualando la variable del objeto mina
   que pasamos como parametro a la nueva creada.
 * \param m de tipo Mina pasado por referencia
 * \return Esta funcion al ser Constructor devuelve *this.
 */

Mina::Mina(const Mina &m){
	simbolo=m.simbolo;
}


/** \brief Destructor de Mina
 *
 * Destructor de Mina: Esta funion destruye un objeto Mina liberando memoria si fuese
   necesario, en este caso no se libera memoria ya que la variable es de tipo caracter.
 * \return Esta funcion al ser Destructor devuelve *this.
 */

Mina::~Mina(){}

/** \brief Funcion getPuntos (Como es virtual no se pone aqui nada)
 *
 * Funcion getPuntos: esta funcion devolvera los puntos correspondientes al tipo de mina que la invoque.
 * \return devuelve el valor de la variable puntos.
 */


/** \brief Funcion imprimeSimbolo
 *
 * Funcion imprimeSimbolo: esta funcion imprime el simbolo correspondiente al tipo de mina de que se trata:
   'E' si es una mina Estandar y 'B'  si es una mina Bonus.
 * \return devuelve void.
 */

void Mina::imprimeSimbolo(ostream &o) const{
	o<<simbolo;
}



// ATRIBUTOS DE LA CLASE MINABONUS

/** \brief Constructor por defecto 
 *
 * Constructor por defecto: Crea un objeto de la clase MinaBonus
 * \return Esta funcion al ser Constructor devuelve *this.
 */

int MinaBonus::puntos=5; 

MinaBonus::MinaBonus(){
	simbolo='B';
}


/** \brief Constructor de Copia
 *
 * Constructor de Copia: este constructor crea una nueva mina bonus a partir de otra que
   pasamos como parametro de entrada del constructor, igualando la variable del objeto mina
   que pasamos como parametro a la nueva creada.
 * \param m de tipo MinaBonus pasado por referencia
 * \return Esta funcion al ser Constructor devuelve *this.
 */

MinaBonus::MinaBonus(const MinaBonus &mb){
	simbolo=mb.simbolo;
}


/** \brief Destructor de MinaBonus
 *
 * Destructor de MinaBonus: Esta funion destruye un objeto MinaBonus liberando memoria si fuese
   necesario, en este caso no se libera memoria ya que las variables son de tipo caracter y tipo entero.
 * \return Esta funcion al ser Destructor devuelve *this.
 */

MinaBonus::~MinaBonus(){
	simbolo=' ';
}


/** \brief Funcion getPuntos
 *
 * Funcion getPuntos: esta funcion simplemente devuelve el valor de la variable puntos, que en este
   caso siempre deberia de valer 5.
 * \return devuelve un 5 o la variable puntos con valor 5.
 */

int MinaBonus::getPuntos() const{
	return puntos;
}


// ATRIBUTOS DE LA CLASE MINAESTANDAR

/** \brief Constructor por defecto
 *
 * Constructor por defecto: Crea un objeto de la clase MinaEstandar
 * \return Esta funcion al ser Constructor devuelve *this.
 */

int MinaEstandar::puntos=1; 

MinaEstandar::MinaEstandar(){
	simbolo='E';
}


/** \brief Constructor de Copia
 *
 * Constructor de Copia: este constructor crea una nueva mina estandar a partir de otra que
   pasamos como parametro de entrada del constructor, igualando la variable del objeto mina
   que pasamos como parametro a la nueva creada.
 * \param m de tipo MinaEstandar pasado por referencia
 * \return Esta funcion al ser Constructor devuelve *this.
 */

MinaEstandar::MinaEstandar(const MinaEstandar &me){
	simbolo=me.simbolo;
}


/** \brief Destructor de MinaEstandar
 *
 * Destructor de MinaEstandar: Esta funion destruye un objeto MinaEstandar liberando memoria si fuese
   necesario, en este caso no se libera memoria ya que las variables son de tipo caracter y tipo entero.
 * \return Esta funcion al ser Destructor devuelve *this.
 */

MinaEstandar::~MinaEstandar(){
	simbolo=' ';
}


/** \brief Funcion getPuntos
 *
 * Funcion getPuntos: esta funcion simplemente devuelve el valor de la variable puntos, que en este
   caso siempre deberia de valer 1.
 * \return devuelve un 1 o la variable puntos con valor 1.
 */

int MinaEstandar::getPuntos() const{
	return puntos;
}
