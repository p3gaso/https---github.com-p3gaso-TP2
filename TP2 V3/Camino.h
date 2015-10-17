#include <iostream>
#include "Casillero.h"


enum DIRECCIONES {IZQUIERDA=1,DERECHA,ARRIBA,ABAJO};

class Camino{
    private:
        Casillero* entrada;
        Casillero* posicionActual;
        Casillero* posicionAnteriorInmediata;
        DIRECCIONES direccionesDisponibles[4];
        DIRECCIONES direccionPrioritaria; /// Analizar en donde es mas util!!!:

        //POST: devuelve el casillero que tengas las coordenadas
        //      ingresadas por parametro. En caso de que no exista devuelve NULL
        Casillero* obtenerCasillero(int coordenadaX,int coordenadaY);

    public:
        //PRE: recibe un enumerado que determina la prioridad
        //      a la hora de realizar el recorrido del laberinto.
        //POST: los punteros a casillero entrada y actual comienzan
        //      apuntando a NULL.
        Camino(DIRECCIONES prioridadDeRecorrido);

        //POST: libera la memoria ocupada
        ~Camino();


        /*  METODOS DE CREACION DE POSICIONES DENTRO DEL CAMINO */
        /*  --------------------------------------------------  */

        //POST:crea el primer casillero con las coordenadas
        //     del bitmap de entrada al laberinto.
        void crearPosicionInicial(int coordenadaXEntrada,int coordenadaYEntrada);

        //PRE: recibe las coordenadas de la nueva posicion en la que estamos ubicados
        //POST: crea un nuevo casillero con las nuevas coordenadas
        //      y lo enlaze con el casillero inmediatamente anterior.
        void generarNuevaPosicion(int coordenadaXNueva,int coordenadaYNueva,Color colorNuevaPosicion);

        //PRE: la direccion primaria que toma el camino puede variar
        //POST: devuelvo la direccion con la que se busca recorrer el laberinto en primera
        //      instancia
        DIRECCIONES obtenerDireccionPrioritaria();

        //PRE: se recibe la direccion prioritaria al recorrer el laberinto
        //POST: modifica el recorrido del camino dependiendo de la direccion prioritaria
        void establecerDireccionPrioritaria(DIRECCIONES direccionPrioritaria);///IMPORTANTE

        /* METODOS DE RECORRIDO DEL CAMINO  */
        /* -------------------------------- */

        //PRE:  el camino debe tener al menos una posicion dentro
        //      NO SE DEBE AVANZAR DE POSICION MIENTRAS SE COMPLETA EL CAMINO
        //POST: lleva el puntero actual a la siguiente posicion del camino
        bool avanzarAPosicionSiguiente();

        //PRE: LLeva a NULL el puntero actual
        void volverAPosicionInicial();

        //PRE: el camino no debe estar vacio
        //POST: devuelve un puntero a las coordenadas de la posicion inicial
        Coordenada* obtenerCoordenadaPosicionInicial();

        //PRE: se debe estar recorriendo el camino
        //POST: devuelve las coordenadas de la posicion actual en la que estamos del camino
        Coordenada* obtenerCoordenadaPosicionActual();

        //POST: devuelve un puntero al color del casillero actual
        Color* obtenerColorCasilleroActual();


};
