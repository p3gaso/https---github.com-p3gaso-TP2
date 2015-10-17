#include "Casillero.h"
Casillero::Casillero(int coordenadaX,int coordenadaY)
{
    coordenadaCasillero = new Coordenada(coordenadaX,coordenadaY);
    this->casilleroContiguo = NULL;
    colorCasillero = new Color(0,0,0);
}

//-------------------------------------------------------------------------

Coordenada* Casillero::obtenerCoordenadas()
{
    return this->coordenadaCasillero;
}


//-------------------------------------------------------------------------

Casillero* Casillero::obtenerCasilleroContiguo()
{
    return this->casilleroContiguo;
}

void Casillero::cambiarCasilleroContiguo(Casillero* casilleroContiguo)
{
    this->casilleroContiguo = casilleroContiguo;
}

//-------------------------------------------------------------------------

void Casillero::asignarColor(unsigned int R,unsigned int G,unsigned int B)
{
    colorCasillero->cambiarColor(R,G,B);
}

//------------------------------------

Color* Casillero::obtenerColorCasillero()
{
    return colorCasillero;
}

//---------------------------------------

Casillero::~Casillero()
{
    delete coordenadaCasillero;
}
