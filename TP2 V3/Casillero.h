#include <iostream>
#include "Coordenada.h"
#include "Color.h"

class Casillero{
    private:
        Coordenada* coordenadaCasillero;
        Color* colorCasillero;
        Casillero* casilleroContiguo;
    public:
        //PRE: el casillero se crea con las coordenadas
        //POST: Se asignan los valores de las coordenadas
        //      y se inicia el color en blanco (255,255,255,0)
        Casillero(int coordendaX,int coordendaY);
        //POST:Libera la memoria usada por la coordenada
        ~Casillero();
        //POST:devuelve un puntero a las coordenadas del casillero
        Coordenada* obtenerCoordenadas();
        //PRE: el puntero casillero siguiente esta en primera instancia apuntando a NULL
        //POST: si no se realizo modificaciones del puntero al casillero siguiente
        //      se devuelve un puntero a NULL
        Casillero* obtenerCasilleroContiguo();
        //PRE: Recibo por parametro el puntero al casillero contiguo
        //POST: Modifico la variable casillero contiguo
        void cambiarCasilleroContiguo(Casillero* casilleroContiguo);
        //PRE: R: Red G:Green, B: Blue
        //POST: asigna un valor a casa posicion del vector color
        void asignarColor(unsigned int R,unsigned int G,unsigned int B);
        //PRE: si el color no esta asigando devuelve (0,0,0)
        Color* obtenerColorCasillero();


};
