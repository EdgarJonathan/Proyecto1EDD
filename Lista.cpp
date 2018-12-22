#include <Lista.h>
#include <iostream>

//***********************************************************************
//***********************CLASE NODO**************************************
//***********************************************************************

NodoUser::NodoUser(Usuario usuario)
{
    this->usuario = usuario;
    this->sig = NULL;
}


//***********************************************************************
//************************CLASE LISTA************************************
//***********************************************************************
bool ListaUsuario::insertar(Usuario usuario)
{
    NodoUser* nuevo= new NodoUser(usuario);

    if(primero == NULL)
    {
        primero = nuevo;
        primero->setSig(primero);
        ultimo = primero;
        std::cout<<"agregamos el primer nodo"<<std::endl;

        return true;
    }else if(buscarId(nuevo->getDato().id))
    {
        ordenar(nuevo);
        std::cout<<"se agrego el nodo y se ordeno la lista"<<std::endl;

        return true;
    }else
    {
        std::cout<<"id ya existe"<<std::endl;
        return false;
    }


}



void ListaUsuario::ordenar(NodoUser* nuevo)
{
    std::string nombreN = nuevo->getDato().nombre;
    NodoUser* actual = primero;

    if( nombreN < primero->getDato().nombre )
    {
        nuevo->setSig(primero);
        primero = nuevo;
    }else if(nombreN >= ultimo->getDato().nombre)
    {
        nuevo->setSig(primero);
        ultimo->setSig(nuevo);
        ultimo=nuevo;

    }else{

        do {

            if((nombreN >= actual->getDato().nombre)&&(nombreN < actual->getSig()->getDato().nombre))
            {
                nuevo->setSig(actual->getSig());
                actual->setSig(nuevo);
                break;
            }

            actual = actual->getSig();
        }while(actual!=primero);

    }
}

NodoUser* ListaUsuario::buscarNodo(std::string id)
{
    NodoUser* tmp = primero;
        while (tmp!=NULL) {
            if(tmp->getDato().id == id){
                return tmp;
            }
            tmp = tmp->getSig();
        }
        return NULL;
}

bool ListaUsuario::buscarId(std::string id)
{
    NodoUser* tmp = primero;
        while (tmp!=NULL) {
            if(tmp->getDato().id == id){
                return true;
            }
            tmp = tmp->getSig();
        }
        return false;

}

//void ListaUsuario::eliminar(std::string id){}
//void ListaUsuario::imprimirLista(){}
//bool buscarId(std::string id);
