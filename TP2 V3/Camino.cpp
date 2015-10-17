#include <iostream>
#include "Camino.h"



Camino::Camino(DIRECCIONES direccionPrioritaria)
{
    this->direccionPrioritaria = direccionPrioritaria;
    this->posicionActual  = NULL;
    this->entrada = NULL;
    this->posicionAnteriorInmediata = NULL;
}

Camino::~Camino()
{
    this->volverAPosicionInicial();
    do
    {
        Casillero* posicionABorrar = this->entrada;
        this->entrada = this->entrada->obtenerCasilleroContiguo();
        delete posicionABorrar;
    }
    while(entrada!=NULL);
}

//---------------------------------------------------------------------------

void Camino::crearPosicionInicial(int coordenadaXEntrada,int coordenadaYEntrada)
{
    this->entrada = new Casillero(coordenadaXEntrada,coordenadaYEntrada);
    this->posicionAnteriorInmediata = this->entrada;
}

//----------

void Camino::generarNuevaPosicion(int coordenadaXNueva,int coordenadaYNueva,Color colorNuevaPosicion)
{
    Casillero* nuevoCasillero = new Casillero(coordenadaXNueva,coordenadaYNueva);
    nuevoCasillero->asignarColor(colorNuevaPosicion.obtenerRojo(),colorNuevaPosicion.obtenerVerde(),colorNuevaPosicion.obtenerAzul());
    this->posicionAnteriorInmediata->cambiarCasilleroContiguo(nuevoCasillero);
    this->posicionAnteriorInmediata = nuevoCasillero;
}


//----------

DIRECCIONES Camino::obtenerDireccionPrioritaria()
{
    return this->direccionPrioritaria;
}


//----------

void Camino::establecerDireccionPrioritaria(DIRECCIONES direccionPrioritaria)
{
    this->direccionPrioritaria = direccionPrioritaria;
}

//------------------------------------------------------------------------------------------


void Camino::volverAPosicionInicial()
{
    this->posicionActual = this->entrada;
}

bool Camino::avanzarAPosicionSiguiente()
{
    if(posicionActual != NULL)
    {
        posicionActual = posicionActual->obtenerCasilleroContiguo();
        return (posicionActual!=NULL);

    }
    throw "No se a iniciado el recorrido del camino";
}

//--------------------------------------------------------------------------------------

Coordenada* Camino::obtenerCoordenadaPosicionInicial()
{
    return this->entrada->obtenerCoordenadas();
}

Coordenada* Camino::obtenerCoordenadaPosicionActual()
{
    if(this->posicionActual!=NULL)
        return this->posicionActual->obtenerCoordenadas();
    throw "No se ha iniciado el recorrido del camino";
}

Color* Camino::obtenerColorCasilleroActual()
{
    if(this->posicionActual!=NULL)
        return this->posicionActual->obtenerColorCasillero();
    throw "No se ha iniciado el recorrido del camino";
}


//----------------------------------------------------------------------------------------


Casillero* Camino::obtenerCasillero(int x,int y)
{
    this->volverAPosicionInicial();

    do
    {
        Coordenada* coordenadaActual = this->posicionActual->obtenerCoordenadas();
        if((coordenadaActual->obtenerX()==x)&&(coordenadaActual->obtenerY()==y))
            return this->posicionActual;//devuelve el puntero al casillero que tiene esa coordenada
    }
    while(this->avanzarAPosicionSiguiente());

    return NULL;//Si no encuentra la coordenada devuelve un puntero a NULL
}





