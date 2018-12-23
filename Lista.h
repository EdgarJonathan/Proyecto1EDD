#ifndef LISTA
#define LISTA

#include <Matriz.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
//*******************************************************************************
//***********************CLASE NODO USUARIO**************************************
//*******************************************************************************

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

//*******************************************************************************
//************************CLASE LISTA USUARIO************************************
//*******************************************************************************
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
    void graficar();
    void encabezado();
    void cuerpo();
    void pie();
    ~ListaUsuario();



};
//***********************************************************************************
//***********************CLASE NODO TRATAMIENTO**************************************
//***********************************************************************************

struct Tratamiento1
{
    std::string nombre;
    std::string costo;

};

struct Tratamiento{
    std::string id;
    std::string nombre;
    std::string costo;
};

class NodoTratamiento
{
    private:
    Tratamiento tratamiento;
    NodoTratamiento *sig;
    NodoTratamiento *ant;


    public:
    NodoTratamiento(Tratamiento tratamiento);
    Tratamiento getDato() { return tratamiento; }
    void    setSig(NodoTratamiento* sig) { this->sig = sig;}
    void    setAnt(NodoTratamiento* ant) {this->ant =ant;}
    NodoTratamiento *getSig() { return sig; }
    NodoTratamiento *getAnt() { return ant; }

};

//************************************************************************************
//************************CLASE LISTA TRATAMIENTOS************************************
//************************************************************************************
class ListaTratamiento
{

    public:




    NodoTratamiento *primero;
    NodoTratamiento *ultimo;


    ListaTratamiento() { primero= NULL; ultimo = NULL; }
    bool Vacia() { return (primero == NULL); }

    bool insertar(Tratamiento tratamiento);
    void ordenar(NodoUser* nuevo);
    bool buscarId(std::string id);
    void eliminar(std::string id);
    void imprimirLista();
    void graficar();
    void encabezado();
    void cuerpo();
    void prueba();
    std::string crearllave();
    void pie();

    ~ListaTratamiento();



};

#endif //LISTA

