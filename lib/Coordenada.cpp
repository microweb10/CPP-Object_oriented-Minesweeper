
#include "Coordenada.h"
/** \file Coordenada.cpp
 * \brief Contiene la definicion de los metodos de la clase Coordenada.
 *
 * AUTORES:

   DNI   45567904-M    Julian Nicolas Herrero
   DNI   74233276-V    Patricia Gallego Rodriguez

   El fichero Coordenada.cpp contiene la definicion de los metodos de la clase Coordenada, asi como
   las posibles sobrecargas de operadores.
 */


/** \brief Constructor por defecto y sobrecargado
 *
 * Constructor por defecto y sobrecargado: este constructor crea una nueva coordenada
   inicializando las variables a 0-0 si no se le pasa ningun parametro. Admite sobrecarga
   de parametros de tal forma que se puede inicializar con cualquier valor admitido mediate
   la funion setCoordX y setCoordY.
 * \param x Contiene el valor (numero entero) de la parte X de la Coordenada.
 * \param y Contiene el valor (numero entero) de la parte Y de la Coordenada.
 * \return Esta funcion al ser Constructor devuelve *this.
 */

Coordenada::Coordenada(int x,int y){
	if(setCoordX(x)!=true)
		coordX=-1;
	if(setCoordY(y)!=true)
		coordY=-1;
}

/** \brief Constructor de Copia
 *
 * Constructor de Copia: este constructor crea una nueva coordenada a partir de otra que
   pasamos como parametro de entrada del constructor, igualando las variables de la coordenada
   que pasamos como parametro a la nueva creada.
 * \param c de tipo Coordenada pasado por referencia
 * \return Esta funcion al ser Constructor devuelve *this.
 */

Coordenada::Coordenada(const Coordenada &c){
	coordX=c.coordX;
	coordY=c.coordY;
}

/** \brief Sobrecarga del Operador =
 *
 * Sobrecarga del Operador =: Esta funion la utilizamos para poder asignar el valor de una
   coordenada que pasamos como parametro a otra con el operador = al igual que hacemos con
   tipos de datos simples.
 * \param c de tipo Coordenada pasado por referencia
 * \return Esta funcion de sobrecarga de un operador devuelve *this.
 */

Coordenada &
Coordenada::operator=(const Coordenada &c){
	coordX=c.coordX;
	coordY=c.coordY;
return *this;
}

/** \brief Destructor de Coordenada
 *
 * Destructor de Coordenada: Esta funion destruye una coordenada liberando memoria si fuese
   necesario, en este caso no se libera memoria ya que las variables son dos de tipo entero
   simplemente les pone valor 0 a dichas variables. (igual que el constructor por defecto)
 * \param No tiene parametros de entrada salvo el propio objeto que la invoca.
 * \return Esta funcion al ser Destructor devuelve *this.
 */

Coordenada::~Coordenada(){
	coordX=-1;
	coordY=-1;
}

/** \brief Funcion getCoordX
 *
 * Funcion getCoordX: Esta funcion obtiene el valor de la variable x de la coordenada que la
   invoca.
 * \param No tiene parametros de entrada salvo el propio objeto que la invoca.
 * \return Esta funcion devuelve un valor entero correspondiente a la parte x de la coordenada.
 */

int Coordenada::getCoordX() const{

return(coordX);
}

/** \brief Funcion setCoordX
 *
 * Funcion setCoordX: Esta funcion valida el valor de la variable x pasada como parameto de la
   coordenada asegurandose que sea un valor no negativo y no nulo. Una vez validado el valor de
   la variable x se almacena en la variable CoordX.
 * \param x de tipo numero entero.
 * \return esta funcion devuelve una variable booleana que sera true cuando se cumplan los requisitos
    mencionados anteriormente.
 */

bool Coordenada::setCoordX(int x){
	bool res=false;
	if (x>=0){
		coordX=(int)x;
		res=true;
	}
	else coordX=-1;
return(res);
}

/** \brief Funcion getCoordY
 *
 * Funcion getCoordY: Esta funcion obtiene el valor de la variable y de la coordenada que la
   invoca.
 * \param No tiene parametros de entrada salvo el propio objeto que la invoca.
 * \return Esta funcion devuelve un valor entero correspondiente a la parte y de la coordenada.
 */

int Coordenada::getCoordY() const{

return(coordY);
}

/** \brief Funcion setCoordY
 *
 * Funcion setCoordY: Esta funcion valida el valor de la variable y pasada como parameto de la
   coordenada asegurandose que sea un valor no negativo y no nulo. Una vez validado el valor de
   la variable y se almacena en la variable CoordY.
 * \param y de tipo numero entero.
 * \return esta funcion devuelve una variable booleana que sera true cuando se cumplan los requisitos
    mencionados anteriormente.
 */

bool Coordenada::setCoordY(int y){
	bool res=false;
	if (y>=0){
		coordY=(int)y;
		res=true;
	}
	else coordY=-1;
return(res);
}

/** \brief Sobrecarga del operador de salida <<
 *
 * Sobrecarga del operador de salida <<: Esta funcion la utilizamos para poder mostrar por la salida
   estandar con la funcion cout una coordenada con el siguiente formato: (CoordX-CoordY).
 * \param o de tipo ostream por referencia.
 * \param c de tipo Coordenada por referencia.
 * \return esta funcion devuelve una variable de tipo ostream.
 */

ostream& operator<<(ostream &o,const Coordenada &c){
	o<<"("<<c.coordX<<"-"<<c.coordY<<")";
return (o);
}

/** \brief Sobrecarga del operador de entrada >>
 *
 * Sobrecarga del operador de entrada >>: Esta funcion la utilizamos para poder leer de la entrada
   estandar con la funcion cin una coordenada con el siguiente formato: (CoordX-CoordY).
 * \param o de tipo istream por referencia.
 * \param c de tipo Coordenada por referencia.
 * \return esta funcion devuelve una variable de tipo istream.
 */

istream& operator>>(istream &o,Coordenada &c){
	int x,y,i=0,g,tam,intp1=0,intg,intp2,aux,aux2;
	bool res=false;
	char total[50];
	o>>total;
	tam=strlen(total);
	intp2=tam-1;
	if(total[i]=='('){
		i++;
		if (total[i]!='-'){
			while ((total[i]>='0')&&(total[i]<='9')) i++;
			if (total[i]=='-'){
				intg=i;
				i++;
				if (total[i]!=')'){
					while ((total[i]>='0')&&(total[i]<='9')) i++;
					if ((i==tam-1)&&(total[i]==')')) res=true;
				}
			}
		}
	}
	if (res==true){
		tam=intg-intp1-1;
		x=0;
		for(i=intp1+1;i<intg;i++) {
			aux=(int)total[i];
			aux=aux-48;
			aux2=1;
			for (g=0;g<tam-1;g++){
				aux2=aux2*10;
			}
			x=x+(aux*aux2);
			tam--;
		}
		tam=intp2-intg-1;
		y=0;
		for(i=intg+1;i<intp2;i++) {
			aux=(int)total[i];
			aux=aux-48;
			aux2=1;
			for (g=0;g<tam-1;g++){
				aux2=aux2*10;
			}
			y=y+(aux*aux2);
			tam--;
		}
		c.setCoordX(x);
		c.setCoordY(y);
	}
	else{
		cerr<<"Coordenada mal introducida"<<endl;
		c.~Coordenada();
	}
return(o);
}


/** \brief Funcion getCoordenadaAleatoria
 *
 * Funcion getCoordenadaAleatoria: Esta funcion cambia la coordenada que invoca el metodo por una creada
   de manera aleatoria por una funcion de C++ llamada rand o drand.
 * \param limiteSupX y limiteSupY de tipo numero entero.
 * \return esta funcion no devuelve nada.
 */

Coordenada Coordenada::getCoordenadaAleatoria(int limiteSupX,int limiteSupY){
	Coordenada coord;
	coord.setCoordX((rand()%limiteSupX)+1);
	coord.setCoordY((rand()%limiteSupY)+1);
return(coord);
}


/** \brief Sobrecarga del operador != (distinto)
 *
 * Sobrecarga del operador != (distinto): Esta funcion comprueba que dos coordenadas son distintas.
 * \param c de tipo Coordenada.
 * \return esta funcion devuelve una variable booleana que sera true cuando la coordenada que invoca la funcion
    sea distinta que la pasada como parametro, y false en caso contrario.
 */

bool Coordenada::operator!=(const Coordenada &c){
	bool res=true;
	if ((coordX==c.coordX)&&(coordY==c.coordY))
		res=false;
return res;
}
