#include "CampoMinas.h"
/** \file CampoMinas.cpp
 * \brief Contiene la definicion de los metodos de la clase CampoMinas.
 *
 * AUTORES:

   DNI   45567904-M    Julian Nicolas Herrero
   DNI   74233276-V    Patricia Gallego Rodriguez

   El fichero CampoMinas.cpp contiene la definicion de los metodos de la clase CampoMinas, asi como
   las posibles sobrecargas de operadores.
 */


/** \brief Constructor por defecto y sobrecargado
 *
 * Constructor por defecto y sobrecargado: este constructor crea un nuevo Campo de Minas
   inicializando las variables a 9,9 si no se le pasa ningun parametro. Admite sobrecarga
   de parametros de tal forma que se puede inicializar con cualquier valor.
 * \param dx Contiene el valor (numero entero) del eje 'x' del Campo de minas, osea cuantas
          columnas tiene el tablero.
 * \param dy Contiene el valor (numero entero) del eje 'y' del Campo de minas, osea cuantas
          filas tiene el tablero.


 * \return Esta funcion al ser Constructor devuelve *this.
 */

CampoMinas::CampoMinas(int dx,int dy){
	bool bien=true;
	int i=0;
	dimx=dx;
	dimy=dy;
	casilla=new Casilla*[dx];
	if(!casilla){
		cerr<<"error en la reserva de memoria"<<endl;
		casilla=NULL;
	}
	else{
		while((i<dx)&&(bien==true)){
			casilla[i]=new Casilla[dy];
			if (!casilla[i]) {
				cerr<<"error en la reserva de memoria"<<endl;
				bien=false;
			}
			i++;
		}
		if (bien!=true){
			i--;
			while(i>=0){delete[] casilla[i];i--;}
			delete[] casilla;
			casilla=NULL;
		}
	}
}


/** \brief Constructor de Copia
 *
 * Constructor de Copia: este constructor crea un nuevo Campo de Minas a partir de otro que
   pasamos como parametro de entrada del constructor, igualando las variables de la coordenada
   que pasamos como parametro a la nueva creada.
 * \param cm de tipo CampoMinas pasado por referencia
 * \return Esta funcion al ser Constructor devuelve *this.
 */

CampoMinas::CampoMinas(const CampoMinas &cm){
	bool bien=true;
	int i=0,j;
	dimx=cm.getDimX();
	dimy=cm.getDimY();
	if((dimx>0)&&(dimy>0)){
		casilla=new Casilla*[dimx];
		if(!casilla) cerr<<"error en la reserva de memoria"<<endl;
		else{
			while((i<dimx)&&(bien==true)){
				casilla[i]=new Casilla[dimy];
				if (!casilla[i]) {
					cerr<<"error en la reserva de memoria"<<endl;
					bien=false;
				}
				i++;
			}
			if (bien!=true){
				i--;
				while(i>=0){delete[] casilla[i];i--;}
				delete[] casilla;
				casilla=NULL;
				dimx=0;
				dimy=0;
			}
			else{
				for(i=0;i<dimx;i++)
					for(j=0;j<dimy;j++)
						casilla[i][j]=cm.casilla[i][j];
			}
		}
	}
	else {
		casilla=NULL;
		dimx=0;
		dimy=0;
	}
}


/** \brief Destructor de CampoMinas
 *
 * Destructor de CampMinas: Esta funion destruye un Campo de Minas liberando toda la memoria
   ocupada para la creacion del campo de minas y vamos a poner las variables de tipo entero
   que contienen las dimensiones del tablero campo de minas a 0.
 * \param No tiene parametros de entrada salvo el propio objeto que la invoca.
 * \return Esta funcion al ser Destructor devuelve *this.
 */

CampoMinas::~CampoMinas(){
	int i;
	bool control=true;
	for (i=0;((i<getDimX())&&(control==true));i++) {
		if(casilla[i]){
			delete[]casilla[i];
		}
		else{
			control=false;
		}
	}
	delete[]casilla;
	casilla=NULL;
	dimx=0;
	dimy=0;
}


/** \brief Funcion getDimX
 *
 * Funcion getDimX: Esta funcion obtiene el valor de la variable dimx del campo de minas que la
   invoca.
 * \param No tiene parametros de entrada salvo el propio objeto que la invoca.
 * \return Esta funcion devuelve un valor entero correspondiente al valor de la variable dimx.
 */

int CampoMinas::getDimX()const{
	return(dimx);
}


/** \brief Funcion getDimY
 *
 * Funcion getDimY: Esta funcion obtiene el valor de la variable dimy del campo de minas que la
   invoca.
 * \param No tiene parametros de entrada salvo el propio objeto que la invoca.
 * \return Esta funcion devuelve un valor entero correspondiente al valor de la variable dimy.
 */

int CampoMinas::getDimY() const{
	return(dimy);
}


/** \brief Funcion getCasilla
 *
 * Funcion getCasilla: Esta funcion devuelve la casilla correspondiente a la coordenada introducida como
   parametro de entrada.
 * \param c de tipo Coordenada.
 * \return Esta funcion devuelve la casilla correspondiente a la coordenada introducida como parametro de entrada.
 */

Casilla& CampoMinas::getCasilla(const Coordenada &c){
	return(casilla[c.getCoordX()-1][c.getCoordY()-1]);
}


/** \brief Funcion hasMina
 *
 * Funcion hasMina: Esta funcion nos indica si en la coordenada que pasamos como parametro hay una mina colocada.
 * \param c de tipo Coordenada.
 * \return Esta funcion devuelve true si la coordenada tiene una mina y false en caso contrario.
 */

bool CampoMinas::hasMina(const Coordenada &c){
	bool res=true;
	if(getCasilla(c).getMina()==NULL){
		res=false;
	}
return(res);
}


/** \brief Funcion marcaCasilla
 *
 * Funcion marcaCasilla: Esta funcion marca la casilla correspondiente a la coordenada que
   recibe la funcion como parametro invocando la funcion setMarcada sobre el objeto casilla
   que le corresponde.
 * \param c de tipo Coordenada.
 * \return esta funcion devuelve una variable booleana que sera true cuando la coordenada coincida
           con una casilla valida del tablero y dicha casilla no haya sido marcada anteriormente
	   y false en caso contrario.
 */

bool CampoMinas::marcaCasilla(const Coordenada &c){
	bool res;
	if ((c.getCoordX()>getDimX())||(c.getCoordY()>getDimY())||(c.getCoordX()<1)||(c.getCoordY()<1)){
		res=false;
	}
	else{
		if (getCasilla(c).getDescubierta()){
			res=false;
		}
		else{
			if (getCasilla(c).getMarcada()){
				res=false;
			}
			else{
				getCasilla(c).setMarcada();
				res=true;
			}
		}
	}
return(res);
}


/** \brief Funcion descubreCasilla
 *
 * Funcion descubreCasilla: Esta funcion descubre la casilla correspondiente a la coordenada que
   recibe la funcion como parametro invocando la funcion setDescubierta sobre el objeto casilla
   que le corresponde.
 * \param c de tipo Coordenada.
 * \return esta funcion devuelve una variable booleana que sera true cuando la coordenada coincida
           con una casilla valida del tablero y dicha casilla no haya sido descubierta anteriormente
	   y false en caso contrario.
 */

bool CampoMinas::descubreCasilla(const Coordenada &c){
	bool res;
	if ((c.getCoordX()>dimx)||(c.getCoordY()>dimy)||(c.getCoordX()<1)||(c.getCoordY()<1)){
		res=false;
	}
	else{
		if (getCasilla(c).getDescubierta()){
			res=false;
		}
		else{
			getCasilla(c).setDescubierta();
			res=true;
		}
	}
return(res);
}


/** \brief Funcion colocaMinas
 *
 * Funcion colocaMinas: Esta funcion coloca las minas aleatoriamente en el campo de minas para poder comenzar
   el juego.
 * \param m de tipo doble puntero a Mina.
 * \return esta funcion devuelve una variable booleana que sera true cuando haya sido posible colocar
    todas las minas correspondientes en el campo de minas y false en caso contrario.
 */

bool CampoMinas::colocaMinas(Mina** m){
	bool bien=true;
	Coordenada c,c2;
	int i,j,cont=0;
	while(m[cont]!=NULL)cont++;
	//if(Aplicacion::getInstancia()!=NULL) cont=Aplicacion::getInstancia()->getNumMinas();No funciona
	for(j=0;((j<cont)&&(bien==true));j++){
		i=0;
		do{
		i++;
		c=c.getCoordenadaAleatoria(getDimX(),getDimY());
		}while((hasMina(c))&&(i<MAX_INTENTOS));
		if (!hasMina(c)){
			getCasilla(c).setMina(*m[j]);
		}
		else{
			cerr<<"Error al colocar las minas (Colocaminas)"<<endl;
			bien=false;
		}
	}
	for(i=1;((i<=getDimX())&&(bien==true));i++){
		for(j=1;j<=getDimY();j++){
			c2.setCoordX(i);
			c2.setCoordY(j);
			setNumMinasAlrededorCasilla(c2);
		}
	}
return(bien);
}


/** \brief Funcion calculaPuntos
 *
 * Funcion calculaPuntos: Esta funcion calcula el total de puntos obtenidos en la partida.
 * \param No tiene parametros de entrada salvo el propio objeto que la invoca.
 * \return esta funcion devuelve una variable entera con el total de puntos obtenidos.
 */

int CampoMinas::calculaPuntos(){
	int puntos=0,i,j;
	Coordenada coord;
	for(i=0;i<getDimX();i++){
		for(j=0;j<getDimY();j++){
			coord.setCoordX(i+1);
			coord.setCoordY(j+1);
			if(getCasilla(coord).getMarcada()){
				if(hasMina(coord)){
					puntos=puntos+(getCasilla(coord).getMina()->getPuntos());
				}
				else{
					puntos--;
				}
			}
		}
	}
	if(puntos<0) puntos=0;
return(puntos);
}


/** \brief Funcion setNumMinasAlrededorCasilla
 *
 * Funcion setNumMinasAlrededorCasilla: Esta funcion calcula el numero de minas que existen alrededor
   de la casilla correspondiente a la coordenada que recibe la funcion como parametro de entrada.
 * \param c de tipo Coordenada.
 * \return esta funcion no devuelve nada por ser void.
 */

void CampoMinas::setNumMinasAlrededorCasilla(Coordenada &c){
	int x=c.getCoordX(), y=c.getCoordY(),minas=0;
	if ((x-1)<1){
		if((y+1)>getDimY()){
			if((casilla[x][y-1]).getMina()!=NULL) minas++;
			if((casilla[x][y-2]).getMina()!=NULL) minas++;
			if((casilla[x-1][y-2]).getMina()!=NULL) minas++;
		}
		else{
			if((y-1)<1){
				if((casilla[x-1][y]).getMina()!=NULL) minas++;
				if((casilla[x][y]).getMina()!=NULL) minas++;
				if((casilla[x][y-1]).getMina()!=NULL) minas++;
			}
			else{
				if((casilla[x][y-1]).getMina()!=NULL) minas++;
				if((casilla[x][y-2]).getMina()!=NULL) minas++;
				if((casilla[x-1][y-2]).getMina()!=NULL) minas++;
				if((casilla[x-1][y]).getMina()!=NULL) minas++;
				if((casilla[x][y]).getMina()!=NULL) minas++;
			}
		}
	}
	else{
		if ((x+1)>getDimX()){
			if((y+1)>getDimY()){
				if((casilla[x-2][y-1]).getMina()!=NULL) minas++;
				if((casilla[x-2][y-2]).getMina()!=NULL) minas++;
				if((casilla[x-1][y-2]).getMina()!=NULL) minas++;
			}
			else{
				if((y-1)<1){
					if((casilla[x-1][y]).getMina()!=NULL) minas++;
					if((casilla[x-2][y]).getMina()!=NULL) minas++;
					if((casilla[x-2][y-1]).getMina()!=NULL) minas++;
				}
				else{
					if((casilla[x-2][y-1]).getMina()!=NULL) minas++;
					if((casilla[x-2][y-2]).getMina()!=NULL) minas++;
					if((casilla[x-1][y-2]).getMina()!=NULL) minas++;
					if((casilla[x-1][y]).getMina()!=NULL) minas++;
					if((casilla[x-2][y]).getMina()!=NULL) minas++;
				}
			}
		}
		else{
			if((y+1)>getDimY()){
				if((casilla[x-2][y-1]).getMina()!=NULL) minas++;
				if((casilla[x-2][y-2]).getMina()!=NULL) minas++;
				if((casilla[x-1][y-2]).getMina()!=NULL) minas++;
				if((casilla[x][y-1]).getMina()!=NULL) minas++;
				if((casilla[x][y-2]).getMina()!=NULL) minas++;
			}
			else{
				if((y-1)<1){
					if((casilla[x-1][y]).getMina()!=NULL) minas++;
					if((casilla[x-2][y]).getMina()!=NULL) minas++;
					if((casilla[x-2][y-1]).getMina()!=NULL) minas++;
					if((casilla[x][y]).getMina()!=NULL) minas++;
					if((casilla[x][y-1]).getMina()!=NULL) minas++;
				}
				else{
					if((casilla[x-2][y-1]).getMina()!=NULL) minas++;
					if((casilla[x-2][y-2]).getMina()!=NULL) minas++;
					if((casilla[x-1][y-2]).getMina()!=NULL) minas++;
					if((casilla[x][y-1]).getMina()!=NULL) minas++;
					if((casilla[x][y-2]).getMina()!=NULL) minas++;
					if((casilla[x-1][y]).getMina()!=NULL) minas++;
					if((casilla[x-2][y]).getMina()!=NULL) minas++;
					if((casilla[x][y]).getMina()!=NULL) minas++;
				}
			}
		}
	}
casilla[x-1][y-1].setNumMinasAlrededor(minas);
}


/** \brief Sobrecarga del operador de salida <<
 *
 * Sobrecarga del operador de salida <<: Esta funcion la utilizamos para poder mostrar por la salida
   estandar con la funcion cout un campo de minas con un formato de tipo tabla o vector bidimensional.
 * \param o de tipo ostream por referencia.
 * \param c de tipo Coordenada por referencia.
 * \return esta funcion devuelve una variable de tipo ostream.
 */

ostream& operator<<(ostream &o,const CampoMinas &ca){
	int ejey,ejex;
	for(ejey=ca.getDimY();ejey>=1;ejey--){
		o<<ejey<<" |";
		for (ejex=1;ejex<=ca.getDimX();ejex++) o<<ca.casilla[ejex-1][ejey-1]<<"|";
		o<<endl;
	}
	o<<"   ";
	for(ejex=1;ejex<=ca.getDimX();ejex++) o<<ejex<<" ";
	o<<endl;
return (o);
}
