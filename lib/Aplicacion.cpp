#include "Aplicacion.h"
/** \file Aplicacion.cpp
 * \brief Contiene la definicion de los metodos de la clase Aplicacion.
 *
 * AUTORES:

   DNI   45567904-M    Julian Nicolas Herrero
   DNI   74233276-V    Patricia Gallego Rodriguez

   El fichero Aplicacion.cpp contiene la definicion de los metodos de la clase Aplicacion, asi como
   las posibles sobrecargas de operadores.
 */


/** \brief Funcion getInstancia
 *
 * Funcion getInstancia: Esta funcion crea una instancia para poder jugar si no estaba creada, si estaba
   creada anteriormente simplemente devuelve el puntero a dicha instancia.
 * \return esta funcion devuelve un puntero a Aplicacion (instancia para poder jugar).
 */

Aplicacion * Aplicacion::pap=NULL;
 
Aplicacion* Aplicacion::getInstancia(){
	if (pap==NULL) {
		pap=new Aplicacion();
		if (!pap) {
			cerr<<"error al inicializar el juego";
			pap=NULL;
		}
	}
return(pap);
}


/** \brief Destructor de Aplicacion
 *
 * Destructor de Aplicacion: Esta funion destruye toda la informacion de la instancia a la aplicacion
   liberando toda la memoria utilizada.
 * \param No tiene parametros de entrada salvo el propio objeto que la invoca.
 * \return Esta funcion al ser Destructor devuelve *this.
 */

Aplicacion::~Aplicacion(){
	int i;
	if(arrayMinas!=NULL){
		for (i=0;i<getDimX();i++) delete[]arrayMinas[i];
		delete[]arrayMinas;
		arrayMinas=NULL;
	}
	if(cm!=NULL){
		delete cm;
		cm=NULL;
	}
	pap=NULL;
	setDimX(9);
	setDimX(9);
	setNumMinasEst(8);
	setNumMinasBonus(2);
}


/** \brief Funcion getNumMinas
 *
 * Funcion getNumMinas: Esta funcion obtiene la cantidad total de minas que hay en el campo de minas.
 * \param No tiene parametros de entrada salvo el propio objeto que la invoca.
 * \return Esta funcion devuelve un valor entero correspondiente al total de minas.
 */

int Aplicacion::getNumMinas()const{
	return(getNumMinasEst()+getNumMinasBonus());
}


/** \brief Funcion getNumMinasBonus
 *
 * Funcion getNumMinasBonus: Esta funcion obtiene la cantidad de minas tipo Bonus que hay en el campo de minas.
 * \param No tiene parametros de entrada salvo el propio objeto que la invoca.
 * \return Esta funcion devuelve un valor entero correspondiente al total de minas tipo Bonus.
 */

int Aplicacion::getNumMinasBonus() const{
	return(numMinasBonus);
}


/** \brief Funcion getNumMinasEst
 *
 * Funcion getNumMinasEst: Esta funcion obtiene la cantidad de minas tipo Estandar que hay en el campo de minas.
 * \param No tiene parametros de entrada salvo el propio objeto que la invoca.
 * \return Esta funcion devuelve un valor entero correspondiente al total de minas tipo Estandar.
 */

int Aplicacion::getNumMinasEst()const{
	return(numMinasEst);
}


/** \brief Funcion getDimX
 *
 * Funcion getDimX: Esta funcion obtiene el valor de la variable dimx del objeto que la
   invoca.
 * \param No tiene parametros de entrada salvo el propio objeto que la invoca.
 * \return Esta funcion devuelve un valor entero correspondiente al valor de la variable dimx.
 */

int Aplicacion::getDimX()const{
	return(dimx);
}


/** \brief Funcion getDimY
 *
 * Funcion getDimY: Esta funcion obtiene el valor de la variable dimy del objeto que la
   invoca.
 * \param No tiene parametros de entrada salvo el propio objeto que la invoca.
 * \return Esta funcion devuelve un valor entero correspondiente al valor de la variable dimy.
 */

int Aplicacion::getDimY() const{
	return(dimy);
}


/** \brief Funcion getArrayMinas
 *
 * Funcion getArrayMinas: Esta funcion devuelve el doble puntero del array de minas.
 * \param No tiene parametros de entrada salvo el propio objeto que la invoca.
 * \return Esta funcion devuelve el doble puntero del array de minas.
 */

Mina** Aplicacion::getArrayMinas() const{
	return(arrayMinas);
}


/** \brief Funcion getCampoMinas
 *
 * Funcion getCampoMinas: Esta funcion devuelve el puntero a CampoMinas.
 * \param No tiene parametros de entrada salvo el propio objeto que la invoca.
 * \return Esta funcion devuelve el puntero a CampoMinas.
 */

CampoMinas* Aplicacion::getCampoMinas()const{
	return(cm);
}


/** \brief Funcion setNumMinasBonus
 *
 * Funcion setNumMinasBonus: Esta funcion cambia la variable numMinasBonus.
 * \param nm de tipo entero con la cantidad de minas Bonus.
 * \return Esta funcion no devuelve nada al ser void.
 */

void Aplicacion::setNumMinasBonus(int nm){
	numMinasBonus=nm;
}


/** \brief Funcion setNumMinasEst
 *
 * Funcion setNumMinasEst: Esta funcion cambia la variable numMinasEst.
 * \param nm de tipo entero con la cantidad de minas Estandar.
 * \return Esta funcion no devuelve nada al ser void.
 */

void Aplicacion::setNumMinasEst(int nm){
	numMinasEst=nm;
}


/** \brief Funcion setDimX
 *
 * Funcion setDimX: Esta funcion cambia la variable dimx.
 * \param dx de tipo entero con la dimension horizontal.
 * \return Esta funcion no devuelve nada al ser void.
 */

void Aplicacion::setDimX(int dx){
	dimx=dx;
}


/** \brief Funcion setDimY
 *
 * Funcion setDimY: Esta funcion cambia la variable dimy.
 * \param dy de tipo entero con la dimension vertical.
 * \return Esta funcion no devuelve nada al ser void.
 */

void Aplicacion::setDimY(int dy){
	dimy=dy;
}


/** \brief Funcion setArrayMinas
 *
 * Funcion setArrayMinas: Esta funcion cambia el valor de la variable arrayMinas.
 * \param am de tipo doble puntero (Constante) a Mina.
 * \return Esta funcion no devuelve nada al ser void..
 */

void Aplicacion::setArrayMinas(Mina** am){
	arrayMinas=am;
}


/** \brief Funcion setCampoMinas
 *
 * Funcion setCampoMinas: Esta funcion cambia el valor de la variable cm.
 * \param cpm de tipo puntero (Constante) a CampoMinas.
 * \return Esta funcion no devuelve nada al ser void..
 */

void Aplicacion::setCampoMinas(CampoMinas* cpm){
	cm=cpm;
}


/** \brief Funcion run
 *
 * Funcion run: Esta funcion inicializa el juego.
 * \param No contiene parametros de entrada.
 * \return Esta funcion no devuelve nada al ser void..
 */

void Aplicacion::run(){
	OpcionMenu opcion;
	do{
		opcion=gestionarMenu();
		switch(opcion){
			case CONFIGURAR: configurar(); break;
			case JUGAR: cout<<"Fin de juego. Ha obtenido "<<jugar()<<" puntos"<<endl;break;
			case SALIR: ;break;
		}
	}while(opcion!=SALIR);
}


/** \brief Funcion gestionarMenu
 *
 * Funcion gestionarMenu: Esta funcion controla el tipo de operacion que queremos hacer del menu del juego.
 * \param No contiene parametros de entrada.
 * \return Esta funcion devuelve la opcion que deseamos ejecutar en una variable de tipo OpcionMenu
 */

OpcionMenu Aplicacion::gestionarMenu(){
	OpcionMenu res;
	int menu;
	do{
	cout<<"1.- Configurar"<<endl;
	cout<<"2.- Jugar"<<endl;
	cout<<"0.- Salir"<<endl;
	cout<<"Introduce opcion de menu: ";
	cin>>menu;
	}while((menu>2)||(menu<0));
	switch (menu){
		case 0: res=SALIR; break;
		case 1: res=CONFIGURAR; break;
		case 2: res=JUGAR; break;
	}
return res;
}


/** \brief Funcion configurar
 *
 * Funcion configurar: Esta funcion nos permite configurar las opciones del juego.
 * \param No contiene parametros de entrada.
 * \return Esta funcion no devuelve nada al ser void
 */

 void Aplicacion::configurar(){
 	int opcion1,opcion2,bonus,estandar;
	cout<<"Introduce num minas estandares: ";
	cin>>estandar;
	setNumMinasEst(estandar);
	cout<<"Introduce num minas bonus: ";
	cin>>bonus;
	setNumMinasBonus(bonus);
	do{
		cout<<"Introduce nueva DimX Campo Minas: ";
		cin>>opcion1;
		cout<<"Introduce nueva DimY Campo Minas: ";
		cin>>opcion2;
	}while((opcion1*opcion2)<(getNumMinasEst()+getNumMinasBonus()));
	setDimX(opcion1);
	setDimY(opcion2);
}


/** \brief Funcion jugar
 *
 * Funcion jugar: Esta funcion nos permite comenzar el juego.
 * \param No contiene parametros de entrada.
 * \return Esta funcion no devuelve nada al ser void
 */

 int Aplicacion::jugar(){
 	Coordenada coord,aux;
	int puntos=0;
	bool bien=true;
	char opcion;
	srand(time(NULL));
	crearCampoMinas();
	crearArrayMinas();
	if (getCampoMinas()!=NULL){
		if(getArrayMinas()!=NULL){
			do{
				cout<<*cm;
				cout<<"Introduce coordenada [(0-0) para salir]: ";
				cin>>coord;
				if ((coord.getCoordX()>0)&&(coord.getCoordY()>0)&&							(coord.getCoordX()<=getDimX())&&(coord.getCoordY()<=getDimY())){
					do{
					cout<<"Disparar (D) o Marcar (M)? ";
					cin>>opcion;
					while (cin.get()!='\n');
					}while ((opcion!='D')&&(opcion!='d')&&(opcion!='M')&&(opcion!='m'));
					if ((opcion=='m')||(opcion=='M'))
						getCampoMinas()->marcaCasilla(coord);
					else{
						getCampoMinas()->descubreCasilla(coord);
						if(getCampoMinas()->hasMina(coord))
							bien=false;
					}
				}
				else{
					if((coord.getCoordX()==0)&&(coord.getCoordY()==0))
						bien=false;
				}
			}while(bien==true);
			puntos=getCampoMinas()->calculaPuntos();
			liberarCampoMinas();
			liberarArrayMinas();
		}
		else {
			liberarCampoMinas();
		}
	}
return (puntos);
}


/** \brief Constructor por defecto
 *
 * Constructor por defecto: este constructor crea una nueva Aplicacion.
 * \param No contiene parametros de entrada
 * \return Esta funcion al ser Constructor devuelve *this.
 */

Aplicacion::Aplicacion(int ocho,int dos,int nueve){
	pap=this;
	arrayMinas=NULL;
	cm=NULL;
	numMinasEst=ocho;
	numMinasBonus=dos;
	dimx=nueve;
	dimy=nueve;
}


/** \brief Funcion crearCampoMinas
 *
 * Funcion crearCampoMinas: Esta funcion crea el campo de minas.
 * \param No contiene parametros de entrada.
 * \return Esta funcion no devuelve nada al ser void
 */

 void Aplicacion::crearCampoMinas(){
	cm=new CampoMinas(getDimX(),getDimY());
	if (!cm){
		cerr<<"error al crear el campo de minas";
		cm=NULL;
	}
}


/** \brief Funcion crearArrayMinas
 *
 * Funcion crearArrayMinas: Esta funcion crea el array con la colocacion de las minas.
 * \param No contiene parametros de entrada.
 * \return Esta funcion no devuelve nada al ser void
 */

 void Aplicacion::crearArrayMinas(){
	bool bien=true;
	int i=0;
	arrayMinas=new Mina*[getNumMinas()];
	if(!arrayMinas) {
		cerr<<"error en la reserva de memoria"<<endl;
		arrayMinas=NULL;
	}
	else{
		while((i<getNumMinasEst())&&(bien==true)){
			arrayMinas[i]=new MinaEstandar();
			if(!arrayMinas[i]){
				cerr<<"error en la reserva de memoria"<<endl;
				bien=false;
			}
		i++;
		}
		while((i<getNumMinas())&&(bien==true)){
			arrayMinas[i]=new MinaBonus();
			if(!arrayMinas[i]){
				cerr<<"error en la reserva de memoria"<<endl;
				bien=false;
			}
		i++;
		}
		if(bien==false){
			for(i=i-2;i>=0;i--){
				delete arrayMinas[i];
			}
			delete[] arrayMinas;
			arrayMinas=NULL;
		}else{
			if(!getCampoMinas()->colocaMinas(arrayMinas)){
				for(i=i-1;i>=0;i--){
					delete arrayMinas[i];
				}
				delete[] arrayMinas;
				arrayMinas=NULL;
			}
		}
	}
}



/** \brief Funcion liberarCampoMinas
 *
 * Funcion liberarCampoMinas: Esta funcion libera toda la memoria ocupada por el campo de minas.
 * \param No contiene parametros de entrada.
 * \return Esta funcion no devuelve nada al ser void
 */

 void Aplicacion::liberarCampoMinas(){
 	if(getCampoMinas()!=NULL){
		delete cm;
		cm=NULL;
	}
}


/** \brief Funcion liberarArrayMinas
 *
 * Funcion liberarArrayMinas: Esta funcion libera toda la memoria ocupada por el array de minas.
 * \param No contiene parametros de entrada.
 * \return Esta funcion no devuelve nada al ser void
 */

 void Aplicacion::liberarArrayMinas(){
 	int i;
 	if(getArrayMinas()!=NULL){
		for(i=0;i<getNumMinas();i++){
			delete arrayMinas[i];
		}
		delete[] arrayMinas;
		arrayMinas=NULL;
	}
}
