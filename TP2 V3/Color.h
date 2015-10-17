#include <iostream>

class Color{
    private:
        int rojo,verde,azul;
    public:
        Color(int rojo,int verde,int azul)
        {
            this->rojo  = rojo;
            this->verde = verde;
            this->azul  = azul;
        };
        int obtenerRojo()
        {
            return this->rojo;
        };
        int obtenerAzul()
        {
            return this->azul;
        };
        int obtenerVerde()
        {
            return this->verde;
        };
        //POST: cambia el valor de rojo, verde y azul del color
        void cambiarColor(int rojo,int verde,int azul)
        {
            this->rojo = rojo;
            this->verde = verde;
            this->azul = azul;
        };

};
