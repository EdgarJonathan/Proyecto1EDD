#include <Lista.h>

//******************************************************************************
//***********************CLASE NODO USUARIO**************************************
//******************************************************************************

NodoUser::NodoUser(Usuario usuario)
{
    this->usuario = usuario;
    this->sig = NULL;
}


//*******************************************************************************
//************************CLASE LISTA USUARIO************************************
//*******************************************************************************
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
    }else if(!buscarId(nuevo->getDato().id))
    {
        ordenar(nuevo);
        std::cout<<"se agrego el nodo y se ordeno la lista"<<std::endl;

        return true;
    }else
    {
        delete nuevo;
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
        do {
            if(tmp->getDato().id.compare(id)==0){
                return tmp;
            }
            tmp = tmp->getSig();
        }while(tmp!=primero);

        return NULL;
}

bool ListaUsuario::buscarId(std::string id)
{
    NodoUser* tmp = primero;
        do {
            if(tmp->getDato().id.compare(id)==0){
                return true;
            }
            tmp = tmp->getSig();
        }while(tmp!=primero);

        return false;

}


void ListaUsuario::imprimirLista()
{
    if(primero!=NULL)
    {
    NodoUser* actual =primero;

    do{
       std::cout <<"<-["<<actual->getDato().nombre<<"]->"<<std::endl;

       actual=actual->getSig();
    }while(actual!=primero);
    }
    else
    {
        std::cout<<"ListaVacia"<<std::endl;
    }
}

void ListaUsuario::graficar()
{
    encabezado();
    cuerpo();
    pie();

    system("dot -Tsvg -O ListaUsuario.dot");
    system("xdg-open ListaUsuario.dot.svg");
}

void ListaUsuario::encabezado()
{
    std::ofstream archivo;
    archivo.open("ListaUsuario.dot",std::ios::out);//abriendo el archivo
    if(archivo.fail()){ std::cout<<"No se pudo crear el archivo"; exit(1);}

        archivo<<"digraph listaUsuarios"<<std::endl;
        archivo<<"{\n"<<std::endl;
        archivo<<"rankdir=LR"<<std::endl;
        archivo<<"nodesep=0.05;"<<std::endl;
        archivo<<"node [shape=box, color=black ,fontsize=25,fontname=\"Italic\","<<std::endl;
        archivo<<"       fontcolor=black,fillcolor=turquoise4 ,style=filled]\n"<<std::endl;






    archivo.close();//cerrar el archivo

}
void ListaUsuario::cuerpo()
{
    std::ofstream archivo;
    archivo.open("ListaUsuario.dot",std::ios::app);//abrimos el archivo en modo anadir
    if(archivo.fail()){ std::cout<<"No se pudo crear el archivo"; exit(1);}

    if(primero!=NULL){

        int i=0;


         NodoUser* actual = primero;
        do
        {
           std::string id =actual->getDato().id;
           std::string nombre =actual->getDato().nombre;
           std::string dir =actual->getDato().direccion;
           std::string tel =actual->getDato().telefono;


           if(actual==primero)
           {
                archivo<<"nd"<<i<<"[label=\"Primero\\nId:"<<id
                        <<"\\nNombre:"<<nombre<<"\\nDir:"<<dir
                        <<"\\nTel:"<<tel<<"\"];"<<std::endl;

                //si existe solo uno nodo que se apunte a si mismo
                if(primero==ultimo)
                {
                    archivo<<"nd"<<i<<"->nd"<<i<<std::endl;
                }else
                {
                    archivo<<"nd"<<i<<"->nd"<<(i+1)<<"[constraint=false];"<<std::endl;
                }

           }else if(actual==ultimo)
           {
               //media vez primero no sea igual al ultimo
               if(!(primero==ultimo))
               {
                   archivo<<"nd"<<i<<"[label=\"Ultimo\\nId:"<<id
                           <<"\\nNombre:"<<nombre<<"\\nDir:"<<dir
                           <<"\\nTel:"<<tel<<"\"];"<<std::endl;

                    archivo<<"nd"<<i<<"->nd0"<<std::endl;

               }


           }else
           {
               archivo<<"nd"<<i<<"[label=\"Id:"<<id
                       <<"\\nNombre:"<<nombre<<"\\nDir:"<<dir
                       <<"\\nTel:"<<tel<<"\"];"<<std::endl;

               archivo<<"nd"<<i<<"->nd"<<(i+1)<<std::endl;

           }

        actual = actual->getSig();
        i++;

        }while(actual!=primero);

    }else
    {
        archivo<<"nd0[label=\"Lista\\nVacia\"]"<<std::endl;

    }

     archivo.close();//cerrar el archivo

}
void ListaUsuario::pie()
{
    std::ofstream archivo;
    archivo.open("ListaUsuario.dot",std::ios::app);//abrimos el archivo en modo anadir
    if(archivo.fail()){std::cout<<"No se pudo crear el archivo"; exit(1);}

        archivo<<"}"<<std::endl;


        archivo.close();//cerrar el archivo


}

void ListaUsuario::eliminar(std::string id)
{

    NodoUser* tmp = primero;
    NodoUser* tmpant = ultimo;
    do {
         if(tmp->getDato().id == id){

             if(tmp==primero)
             {
                primero = primero->getSig();
                ultimo->setSig(primero);

                tmp->setSig(NULL);

                delete tmp;

                 std::cout<<"Se elimino el primer nodo "<<std::endl;
                break;


             }else if(tmp==ultimo)
             {
                tmpant->setSig(primero);
                ultimo =tmpant;

                tmp->setSig(NULL);
                delete tmp;

                 std::cout<<"Se elimino el ultimo  nodo "<<std::endl;
                break;

             }else
             {
                tmpant->setSig(tmp->getSig());


                tmp->setSig(NULL);
                delete tmp;
                std::cout<<"Se elimino un nodo de en medio"<<std::endl;
                break;

             }

        }
        tmp = tmp->getSig();
        tmpant =tmpant->getSig();
    }while(tmp!=primero);

}
//***********************************************************************************
//***********************CLASE NODO TRATAMIENTO**************************************
//***********************************************************************************
NodoTratamiento::NodoTratamiento(Tratamiento tratamiento)
{
        this->tratamiento=tratamiento;
        this->sig=NULL;
        this->ant=NULL;

}

//************************************************************************************
//************************CLASE LISTA TRATAMIENTOS************************************
//************************************************************************************
bool ListaTratamiento::insertar(Tratamiento tratamiento)
{
     NodoTratamiento* nuevo= new NodoTratamiento(tratamiento);

     if(primero==NULL)
     {
         primero = nuevo;
         primero->setSig(primero);
         primero->setAnt(primero);
         ultimo = primero;

         std::cout<<"agregamos el primer nodo"<<std::endl;
         return true;
     }else  if(!(buscarId(tratamiento.id)))
      {
            nuevo->setSig(primero);
            nuevo->setAnt(ultimo);
            primero->setAnt(nuevo);
            ultimo->setSig(nuevo);
            primero=nuevo;
            std::cout<<"agregamos un nodo"<<std::endl;

         return true;
    }else
    {
         delete nuevo;
        //id ya existe
          std::cout<<"id ya existe"<<std::endl;
        return false;
    }

}

bool ListaTratamiento::buscarId(std::string id)
{

    NodoTratamiento* tmp = primero;
        do {
            if(tmp->getDato().id.compare(id)==0){
                return true;
            }
            tmp = tmp->getSig();
        }while(tmp!=primero);

        return false;
}


std::string ListaTratamiento::crearllave()
{
      static char aleatorio[10];
      srand(time(NULL));
      for(int i=0; i < 9; i++)
      {
           if((i>=0)&&(i<5))
           {
              aleatorio[i] = 65 + rand() % (90-65);
           }else
           {
               aleatorio[i] = 48 + rand() % (57-48);
           }
       }

        std::string aux =std::string(aleatorio);
       return aux;
}

void ListaTratamiento::imprimirLista()
{
    if(primero!=NULL)
    {
    NodoTratamiento* actual =primero;

    do{
        std::string nombre=actual->getDato().nombre;
        std::string id = actual->getDato().id;
        std::string costo= actual->getDato().costo;

       std::cout <<"<-["<<id<<","<<nombre<<","<<costo<<"]->"<<std::endl;

       actual=actual->getSig();
    }while(actual!=primero);
    }
    else
    {
        std::cout<<"ListaVacia"<<std::endl;
    }

}

void ListaTratamiento::prueba(){}

void ListaTratamiento::graficar()
{
    encabezado();
    cuerpo();
    pie();

    system("dot -Tsvg -O ListaTratamiento.dot");
    system("xdg-open ListaTratamiento.dot.svg");
}
void ListaTratamiento::encabezado()
{
    std::ofstream archivo;
    archivo.open("ListaTratamiento.dot",std::ios::out);//abriendo el archivo
    if(archivo.fail()){ std::cout<<"No se pudo crear el archivo"; exit(1);}

        archivo<<"digraph listaTratamiento"<<std::endl;
        archivo<<"{\n"<<std::endl;
        archivo<<"rankdir=LR"<<std::endl;
        archivo<<"nodesep=0.05;"<<std::endl;
        archivo<<"node [shape=box, color=black ,fontsize=25,fontname=\"Italic\","<<std::endl;
        archivo<<"       fontcolor=black,fillcolor=turquoise4 ,style=filled]\n"<<std::endl;

    archivo.close();//cerrar el archivo
}
void ListaTratamiento::cuerpo()
{
    std::ofstream archivo;
    archivo.open("ListaTratamiento.dot",std::ios::app);//abrimos el archivo en modo anadir
    if(archivo.fail()){ std::cout<<"No se pudo crear el archivo"; exit(1);}

    if(primero!=NULL){

        int i=0;


         NodoTratamiento* actual = primero;
        do
        {
           std::string id =actual->getDato().id;
           std::string nombre =actual->getDato().nombre;
           std::string costo =actual->getDato().costo;


           if(actual==primero)
           {
                archivo<<"nd"<<i<<"[label=\"Primero\\nId:"<<id
                        <<"\\nNombre:"<<nombre<<"\\nCosto:"<<costo
                        <<"\"];"<<std::endl;

                //si existe solo uno nodo que se apunte a si mismo
                if(primero==ultimo)
                {
                    archivo<<"nd"<<i<<"->nd"<<i<<"[dir=both];"<<std::endl;
                }else
                {
                    archivo<<"nd"<<i<<"->nd"<<(i+1)<<"[constraint=false, dir=both];"<<std::endl;
                }

           }else if(actual==ultimo)
           {
               //media vez primero no sea igual al ultimo
               if(!(primero==ultimo))
               {
                   archivo<<"nd"<<i<<"[label=\"Ultimo\\nId:"<<id
                           <<"\\nNombre:"<<nombre<<"\\nCosto:"<<costo
                           <<"\"];"<<std::endl;

                    archivo<<"nd"<<i<<"->nd0"<<"[dir=both];"<<std::endl;

               }


           }else
           {
               archivo<<"nd"<<i<<"[label=\"Id:"<<id
                       <<"\\nNombre:"<<nombre<<"\\nCosto:"<<costo
                       <<"\"];"<<std::endl;

               archivo<<"nd"<<i<<"->nd"<<(i+1)<<"[dir=both];"<<std::endl;

           }

        actual = actual->getSig();
        i++;

        }while(actual!=primero);

    }else
    {
        archivo<<"nd0[label=\"Lista\\nVacia\"]"<<std::endl;

    }

     archivo.close();//cerrar el archivo

}
void ListaTratamiento::pie()
{
    std::ofstream archivo;
    archivo.open("ListaTratamiento.dot",std::ios::app);//abrimos el archivo en modo anadir
    if(archivo.fail()){std::cout<<"No se pudo crear el archivo"; exit(1);}

        archivo<<"}"<<std::endl;


      archivo.close();//cerrar el archivo
}


//void ListaTratamiento::ordenar(NodoUser* nuevo){}
//void ListaTratamiento::eliminar(std::string id){}
