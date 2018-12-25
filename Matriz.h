#ifndef Matriz
#define Matriz

#include <iostream>
#include <stdlib.h>


struct Cita
{
    std::string transaccion;
    std::string tratamiento;
    std::string idUsuario;
    std::string  estado;
};

struct Hora
{
    std::string horaInicio;
    std::string horaFin;
};

struct Dia
{
    std::string diaString;
    int diaEntero;
};

//********************************************************************************
//************************CLASE NODO ORTOGONAL************************************
//********************************************************************************
class NodoOrtogonal
{
    private:
        Hora fila;
        Dia  col;
        Cita cita;

        NodoOrtogonal* arriba;
        NodoOrtogonal* abajo;
        NodoOrtogonal* siguiente;
        NodoOrtogonal* anterior;
    public:
    NodoOrtogonal(Cita cita,Hora fila, Dia col);

    Hora getFila(){return fila;}
    Dia  getCol(){return col;}
    Cita getCita(){return cita;}

    void setFila(Hora fila){this->fila=fila;}
    void setCol(Dia col) {this->col=col;}
    void setCita(Cita cita){this->cita = cita;}

    NodoOrtogonal* getArriba(){return arriba;}
    NodoOrtogonal* getAbajo(){return abajo;}
    NodoOrtogonal* getSig(){return siguiente;}
    NodoOrtogonal* getAnt(){return anterior;}

    void setArriba(NodoOrtogonal* arriba){this->arriba=arriba;}
    void setAbajo(NodoOrtogonal* abajo){this->abajo=abajo;}
    void setSig(NodoOrtogonal* sig){this->siguiente=sig;}
    void setAnt(NodoOrtogonal* ant){this->anterior=ant;}



};

//********************************************************************************
//************************CLASE LISTA ORTOGONAL***********************************
//********************************************************************************
class ListaOrtogonal
{

    public:
    NodoOrtogonal* primeroFila;
    NodoOrtogonal* ultimoFila;
    NodoOrtogonal* primeroCol;
    NodoOrtogonal* ultimoCol;


    ListaOrtogonal();
    std::string insertarFila(NodoOrtogonal* nuevo);
    bool buscarTransaccionFila(std::string transaccion);
    void ordenarFila(NodoOrtogonal* nuevo);


    std::string insertarCol(NodoOrtogonal* nuevo);
    bool buscarTransaccionCol(std::string transaccion);
    void ordenarCol(NodoOrtogonal* nuevo);

};

//********************************************************************************
//***********************CLASE NODO FILA******************************************
//********************************************************************************
class NodoFila
{

    public:
    Hora hora;
    NodoFila* arriba;
    NodoFila*  abajo;
    ListaOrtogonal* listHorizontal;


    NodoFila(Hora hora);

};


//********************************************************************************
//************************CLASE LISTA FILA ***************************************
//********************************************************************************
class ListaFila
{

    public:
    NodoFila* primero;
    NodoFila* ultimo;

    ListaFila();

    std::string insertar(NodoOrtogonal* nuevo);
    NodoFila* buscarFila(Hora hora);
    void ordenar(NodoFila* nuevo);


};

//********************************************************************************
//************************CLASE NODO COLUMNA *************************************
//********************************************************************************
class NodoCol
{

    public:
    Dia dia;
    NodoCol* sig;
    NodoCol*  ant;
    ListaOrtogonal* listVertical;


    NodoCol(Dia dia);

};
//********************************************************************************
//************************CLASE LISTA COLUMNA ************************************
//********************************************************************************
class ListaCol
{

    public:
    NodoCol* primero;
    NodoCol* ultimo;

    ListaCol();

    std::string insertar(NodoOrtogonal* nuevo);
    NodoCol* buscarFila(Dia dia);
    void ordenar(NodoCol* nuevo);


};

//********************************************************************************
//************************CLASE MATRIZ ORTOGONAL**********************************
//********************************************************************************

#endif //Matriz
