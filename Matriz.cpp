#include <Matriz.h>

nodoOrtogonal::nodoOrtogonal(datoOrt dato, int x, int y)
{
    this->dato=dato;
    this->x=x;
    this->y=y;

    arriba=NULL;
    abajo=NULL;
    derecha=NULL;
    izquierda=NULL;

}
