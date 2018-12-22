#ifndef Matriz
#define Matriz

#include <iostream>
#include <stdlib.h>


//nodo a modificar informacion
struct datoOrt{
    std::string dato;
};

struct datoCabecera
{


};





class nodoOrtogonal
{
    public:
    datoOrt dato;
    nodoOrtogonal* arriba;
    nodoOrtogonal* abajo;
    nodoOrtogonal* izquierda;
    nodoOrtogonal* derecha;
    int x,y;


    //metodos
    nodoOrtogonal(datoOrt dato, int x, int y);

};


#endif //Matriz
