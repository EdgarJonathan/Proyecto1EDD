#ifndef LISTA
#define LISTA

#include <Matriz.h>
#include <iostream>

//***********************************************************************
//***********************CLASE NODO**************************************
//***********************************************************************

struct Usuario{
    std::string id;
    std::string nombre;
    std::string direccion;
    std::string telefono;
};

class NodoUser
{
    private:
    Usuario usuario;
    NodoUser *sig;

    public:
    NodoUser(Usuario usuario);
    Usuario getDato() { return usuario; }
    void    setSig(NodoUser* sig) { this->sig = sig;}
    NodoUser *getSig() { return sig; }

};

//***********************************************************************
//************************CLASE LISTA************************************
//***********************************************************************


class ListaUsuario
{

    public:

    NodoUser *primero;
    NodoUser *ultimo;


    ListaUsuario() { primero= NULL; ultimo = NULL; }
    bool Vacia() { return (primero == NULL); }

    bool insertar(Usuario usuario);
    void ordenar(NodoUser* nuevo);
    NodoUser* buscarNodo(std::string id);
    bool buscarId(std::string id);
    void eliminar(std::string id);
    void imprimirLista();

    ~ListaUsuario();





};

#endif //LISTA

