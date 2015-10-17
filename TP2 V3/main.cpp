/**
    Si no funciona Ctrl+F11, en Code Blocks o entro compilador
    busquen la opcion Rebuild...

    ACERCA DE CAMINO..................

    *Incluí los tda Color y Coordenada... por un tema de sobrecarga de parametros.
    *Los caminos se recorren con un "hacer mientras", (do while() ), trate de q se pareciera
    los mas posible a una lista pero perdia claridad..
    *los metodos para recorrer son:
            - volverAPosicionInicial que me lleva a al entrada del camino.
            - avanzarAPosicionSiguiente que me lleva a la siguiente posicion del camino.
            - TDA Coordenada, TDA Color : son muy sencillos solo miren la implementacion

    *A TENER EN CUENTA! : Siempre se manejan puntero del color y la coordenada de la posicion
    en la que nos encontremos para evitar hacer una copia inecesaria.. ! :) es para ahorrar memoria

    PDT: CUALQUIER CONSULTA DE LOS TDA QUE IMPLEMENTE ME AVISAN POR WS O POR GMAIL :'-)

            ..... Faltan Mejoras ... Tdv estoy trabajando en eso u.U


*/
#include <iostream>
#include "Camino.h"



using namespace std;

int main()
{
    cout<<"Creacion camino de prueba!..."<<endl;
    cout<<"Es un camino Simple que tiene la forma del numero 5 "<<endl;
    cout<<"Usen este ejemplo para poder manejar el camino en el BMP"<<endl;


    Color colorEjemplo(0,255,255);

    Camino caminoDePrueba(IZQUIERDA);
    caminoDePrueba.crearPosicionInicial(20,0);// Entrada
    caminoDePrueba.generarNuevaPosicion(10,0,colorEjemplo);
    caminoDePrueba.generarNuevaPosicion(10,10,colorEjemplo);
    caminoDePrueba.generarNuevaPosicion(20,10,colorEjemplo);
    caminoDePrueba.generarNuevaPosicion(20,20,colorEjemplo);
    caminoDePrueba.generarNuevaPosicion(10,20,colorEjemplo);


    ///-----

    ///---

    caminoDePrueba.volverAPosicionInicial();//LLeva a la entrada del camino

    do
    {
        Coordenada* coordenadaActual = caminoDePrueba.obtenerCoordenadaPosicionActual();
        cout<<"La Posicion Actual tiene coordenadas X: "<<coordenadaActual->obtenerX()<<"  Y: "<<coordenadaActual->obtenerY()<<endl;
        Color* colorActual = caminoDePrueba.obtenerColorCasilleroActual();
        cout<<"El color de este casillero es R: "<<colorActual->obtenerRojo()<<"  G: "
        <<colorActual->obtenerVerde()<<"  B: "<<colorActual->obtenerAzul()<<endl;

    }
    while(caminoDePrueba.avanzarAPosicionSiguiente());//Avanza a la posicion siguiente del camino

    ///----


    return 0;
}
