#include <iostream>

#ifndef LABERINTO_H_INCLUDED

class Coordenada{
    private:
        int x,y;

    public:
        //PRE:
        //POST: inicia los atributos
        Coordenada(int x,int y){
            this->x = x;
            this->y = y;
        };
        //POST: obtengo el valor de X
        int obtenerX()
        {
            return this->x;
        };
        //POST: obtengo el valor de Y
        int obtenerY()
        {
            return this->y;
        };

};

