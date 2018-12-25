#include <Matriz.h>
//********************************************************************************
//************************CLASE NODO ORTOGONAL************************************
//********************************************************************************
NodoOrtogonal::NodoOrtogonal(Cita cita,Hora fila, Dia col)
{
    this->cita = cita;
    this->fila = fila;
    this->col  = col ;

    this->arriba    = NULL;
    this->abajo     = NULL;
    this->anterior  = NULL;
    this->siguiente = NULL;
}

//********************************************************************************
//************************CLASE LISTA ORTOGONAL***********************************
//********************************************************************************
 ListaOrtogonal::ListaOrtogonal()
 {
     primeroFila = NULL;
     primeroCol  = NULL;
     ultimoFila  = NULL;
     ultimoCol   = NULL;
 }

 std::string ListaOrtogonal::insertarFila(NodoOrtogonal* nuevo)
 {

     std::string respuesta="";

     if(primeroFila==NULL)
     {
        primeroFila=nuevo;
        primeroFila->setSig(NULL);
        primeroFila->setAnt(NULL);
        ultimoFila=primeroFila;

        respuesta="Se ingreso el primer nodo fila";
     }else if(!(buscarTransaccionFila(nuevo->getCita().transaccion)))
     {
         ordenarFila(nuevo);

         respuesta="Se ingreso correctamente nodo fila";
     }else
     {
        respuesta="Id existe nodo fila ";
     }

     return respuesta;
 }

 bool ListaOrtogonal::buscarTransaccionFila(std::string transaccion)
 {
     NodoOrtogonal* tmp = primeroFila;
         while (tmp!=NULL) {
             if(tmp->getCita().transaccion ==transaccion){
                 return true;
             }
             tmp = tmp->getSig();
         }
         return false;

 }

 void ListaOrtogonal::ordenarFila(NodoOrtogonal*  nuevo)
 {

    NodoOrtogonal* actualFila = primeroFila;

    //si el nuevo es menor al primero
    if(nuevo->getCol().diaEntero < primeroFila->getCol().diaEntero)
    {
        primeroFila->setAnt(nuevo);
        nuevo->setSig(primeroFila);
        nuevo->setAnt(NULL);
        primeroFila=nuevo;
    }//si  es mayor o igual al ultimo
    else if(nuevo->getCol().diaEntero > ultimoFila->getCol().diaEntero)
    {
            ultimoFila->setSig(nuevo);
            nuevo->setAnt(ultimoFila);
            nuevo->setSig(NULL);
            ultimoFila= nuevo;
    }//recoriendo la lista si nuevo es mayor o igual actual
     //y si nuevo es menor o igual siguiente de actual
    else
    {
        while (actualFila!=ultimoFila) {

            if((nuevo->getCol().diaEntero > actualFila->getCol().diaEntero)
                &&(nuevo->getCol().diaEntero < actualFila->getSig()->getCol().diaEntero)  )
            {
                nuevo->setSig(actualFila->getSig());
                nuevo->setAnt(actualFila);
                actualFila->getSig()->setAnt(nuevo);
                actualFila->setSig(nuevo);
                break;
            }

            actualFila= actualFila->getSig();
        }
    }

 }

 std::string ListaOrtogonal::insertarCol(NodoOrtogonal* nuevo)
 {


        std::string respuesta="";

        if(primeroCol==NULL)
        {
            primeroCol= nuevo;
            primeroCol->setAbajo(NULL);
            primeroCol->setArriba(NULL);
            ultimoCol = primeroCol;
            respuesta="se ingreso correctamente nodo col";

        }else if(!(buscarTransaccionCol(nuevo->getCita().transaccion)))
        {
            ordenarCol(nuevo);
            respuesta="se ingreso correctamente nodo col";
        }else
        {
            respuesta="Id existe ";
        }

    return respuesta;

 }

 bool ListaOrtogonal::buscarTransaccionCol(std::string transaccion)
 {

     NodoOrtogonal* tmp = primeroCol;
         while (tmp!=NULL) {
             if(tmp->getCita().transaccion ==transaccion){
                 return true;
             }
             tmp = tmp->getAbajo();
         }
         return false;
 }

 void ListaOrtogonal::ordenarCol(NodoOrtogonal* nuevo)
 {

     NodoOrtogonal* actualCol = primeroCol;

     //si el nuevo es menor al primero
     if(nuevo->getFila().horaInicio <= primeroCol->getFila().horaInicio)
     {
         primeroCol->setArriba(nuevo);
         nuevo->setAbajo(primeroCol);
         nuevo->setArriba(NULL);
         primeroCol=nuevo;
     }//si  es mayor o igual al ultimo
     else if(nuevo->getFila().horaInicio >= ultimoCol->getFila().horaInicio)
     {
             ultimoCol->setAbajo(nuevo);
             nuevo->setArriba(ultimoCol);
             nuevo->setAbajo(NULL);
             ultimoCol= nuevo;
     }//recoriendo la lista si nuevo es mayor o igual actual
      //y si nuevo es menor o igual siguiente de actual
     else
     {
         while (actualCol!=ultimoCol) {

             if((nuevo->getFila().horaInicio>= actualCol->getFila().horaInicio)
                 &&(nuevo->getFila().horaInicio<= actualCol->getAbajo()->getFila().horaInicio))
             {
                 nuevo->setAbajo(actualCol->getAbajo());
                 nuevo->setArriba(actualCol);
                 actualCol->getAbajo()->setArriba(nuevo);
                 actualCol->setAbajo(nuevo);
                 break;
             }

             actualCol= actualCol->getAbajo();
         }
     }


 }

//********************************************************************************
//***********************CLASE NODO FILA******************************************
//********************************************************************************
 NodoFila::NodoFila(Hora hora)
 {
     this->hora = hora;
     this->abajo =NULL;
     this->arriba=NULL;
     this->listHorizontal =NULL;

 }

//********************************************************************************
//************************CLASE LISTA FILA ***************************************
//********************************************************************************
 ListaFila::ListaFila()
 {
     this->primero=NULL;
     this->ultimo =NULL;

 }

 std::string ListaFila::insertar(NodoOrtogonal *nuevo)
 {

        std::string respuesta="";


     if(primero==NULL)
     {

         NodoFila* nuevoFila = new NodoFila(nuevo->getFila());

         nuevoFila->listHorizontal = new ListaOrtogonal();
         respuesta =  nuevoFila->listHorizontal->insertarFila(nuevo);

         primero=nuevoFila;
         primero->abajo =NULL;
         primero->arriba = NULL;
         ultimo=primero;

         respuesta ="Se ingreso la primera Fila y "+respuesta;


     }//si no existe el nodo se deberar crear y ordenar en la lista
     else if(buscarFila(nuevo->getFila())==NULL)
     {

         NodoFila* nuevoFila = new NodoFila(nuevo->getFila());
         nuevoFila->listHorizontal = new ListaOrtogonal();

         respuesta =  nuevoFila->listHorizontal->insertarFila(nuevo);

          ordenar(nuevoFila);
          respuesta ="Se agrego la Fila se ordeno y "+respuesta;

     }//si el nodo existe solo se utliza y se envia el nodoortogonal
     else
     {
         NodoFila* aux = buscarFila(nuevo->getFila());

       respuesta= aux->listHorizontal->insertarFila(nuevo);

        respuesta ="se utilizo la fila ya creada y "+respuesta;

     }


     return respuesta;
 }

 NodoFila* ListaFila::buscarFila(Hora hora)
 {

     NodoFila* tmp = primero;

         while (tmp!=NULL) {

             if((tmp->hora.horaInicio==hora.horaInicio)&&
                 (tmp->hora.horaFin==hora.horaFin)){

                 return tmp;
             }
             tmp = tmp->abajo;
         }

         return NULL;
 }

 void ListaFila::ordenar(NodoFila* nuevo)
 {
       NodoFila* actual = primero;
     //si el nuevo es menor al primero
       if(nuevo->hora.horaInicio < primero->hora.horaInicio)
       {
           primero->arriba=nuevo;
           nuevo->abajo = primero;
           nuevo->arriba=NULL;
           primero=nuevo;


       }//si  es mayor o igual al ultimo
       else if(nuevo->hora.horaInicio >= ultimo->hora.horaInicio)
       {
           ultimo->abajo = nuevo;
           nuevo->arriba = ultimo;
           nuevo->abajo  = NULL;
           ultimo = nuevo;

       }//recoriendo la lista si nuevo es mayor o igual actual
        //y si nuevo es menor o igual siguiente de actual
       else
       {
           while(actual!=ultimo)
           {

               if((nuevo->hora.horaInicio >= actual->hora.horaInicio)
                  &&(nuevo->hora.horaInicio <= actual->abajo->hora.horaInicio))
               {
                    nuevo->abajo =actual->abajo;
                    nuevo->arriba =  actual;
                    nuevo->abajo->arriba =nuevo;
                    actual->abajo = nuevo;
                   break;
               }

               actual = actual->abajo;
           }

       }
 }

//********************************************************************************
//************************CLASE NODO COLUMNA *************************************
//********************************************************************************
 NodoCol::NodoCol(Dia dia)
 {
    this->dia=dia;
    this->sig=NULL;
    this->ant =NULL;
    this->listVertical=NULL;

 }
//********************************************************************************
//************************CLASE LISTA COLUMNA ************************************
//********************************************************************************
 ListaCol::ListaCol()
 {
     this->primero=NULL;
     this->ultimo=NULL;
 }

 std::string ListaCol::insertar(NodoOrtogonal* nuevo)
 {

        std::string respuesta="";

        if(primero==NULL)
        {
 
        }


//      NodoFila* nuevoFila = new NodoFila(nuevo->getFila());

//      nuevoFila->listHorizontal = new ListaOrtogonal();
//      respuesta =  nuevoFila->listHorizontal->insertarFila(nuevo);

//      primero=nuevoFila;
//      primero->abajo =NULL;
//      primero->arriba = NULL;
//      ultimo=primero;

//      respuesta ="Se ingreso la primera Fila y "+respuesta;


//  }//si no existe el nodo se deberar crear y ordenar en la lista
//  else if(buscarFila(nuevo->getFila())==NULL)
//  {

//      NodoFila* nuevoFila = new NodoFila(nuevo->getFila());
//      nuevoFila->listHorizontal = new ListaOrtogonal();

//      respuesta =  nuevoFila->listHorizontal->insertarFila(nuevo);

//       ordenar(nuevoFila);
//       respuesta ="Se agrego la Fila se ordeno y "+respuesta;

//  }//si el nodo existe solo se utliza y se envia el nodoortogonal
//  else
//  {
//      NodoFila* aux = buscarFila(nuevo->getFila());

//    respuesta= aux->listHorizontal->insertarFila(nuevo);

//     respuesta ="se utilizo la fila ya creada y "+respuesta;

//  }


  return respuesta;


 }






 NodoCol* ListaCol::buscarFila(Dia dia){}
 void ListaCol::ordenar(NodoCol* nuevo){}
//********************************************************************************
//************************CLASE MATRIZ ORTOGONAL**********************************
//********************************************************************************
