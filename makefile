# Este fichero no se debe modificar. La practica debe compilar con este fichero
# situado en el directorio raiz del proyecto (del que cuelgan lib src e include).
# Las clases Mina, MinaBonus y MinaEstandar se implementaran juntas en los ficheros
# Mina.h y Mina.cpp
#

COMP=g++
OPC=-g -Wall
OBJS=main.o Coordenada.o Casilla.o CampoMinas.o Aplicacion.o Mina.o

.PHONY=clean doc
 
main: $(OBJS)  
	$(COMP) $(OPC) $(OBJS) -I ./include -o main
main.o: ./src/main.cpp
	$(COMP) $(OPC) -c ./src/main.cpp -I ./include

CampoMinas.o: ./lib/CampoMinas.cpp 
	$(COMP) $(OPC) -c ./lib/CampoMinas.cpp -I ./include	
	
Casilla.o: ./lib/Casilla.cpp 
	$(COMP) $(OPC) -c ./lib/Casilla.cpp -I ./include	
	
Coordenada.o: ./lib/Coordenada.cpp 
	$(COMP) $(OPC) -c ./lib/Coordenada.cpp -I ./include

Aplicacion.o: ./lib/Aplicacion.cpp
	$(COMP) $(OPC) -c ./lib/Aplicacion.cpp -I ./include

Mina.o: ./lib/Mina.cpp
	$(COMP) $(OPC) -c ./lib/Mina.cpp -I ./include

clean:
	-rm -rf main *.o doc *~

doc:
	doxygen



