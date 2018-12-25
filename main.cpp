#include <iostream>
#include <Lista.h>
#include <Matriz.h>



int main() {

//    Usuario miUsuario1;
//    miUsuario1.direccion ="12av13-64 Ramirez";
//    miUsuario1.id        ="R121";
//    miUsuario1.nombre    ="Juanito";
//    miUsuario1.telefono  ="40589467";

//    Usuario miUsuario2;
//    miUsuario2.direccion ="12av13-64 Ramirez";
//    miUsuario2.id        ="R122";
//    miUsuario2.nombre    ="Omar";
//    miUsuario2.telefono  ="40589467";

//    Usuario miUsuario3;
//    miUsuario3.direccion ="12av13-64 Ramirez";
//    miUsuario3.id        ="R123";
//    miUsuario3.nombre    ="anastacia";
//    miUsuario3.telefono  ="40589467";

//    Usuario miUsuario4;
//    miUsuario4.direccion ="12av13-64 Ramirez";
//    miUsuario4.id        ="R124";
//    miUsuario4.nombre    ="maria";
//    miUsuario4.telefono  ="40589467";

//    Usuario miUsuario5;
//    miUsuario5.direccion ="12av13-64 Ramirez";
//    miUsuario5.id        ="R125";
//    miUsuario5.nombre    ="amsterdam";
//    miUsuario5.telefono  ="40589467";

//    Usuario miUsuario6;
//    miUsuario6.direccion ="12av13-64 Ramirez";
//    miUsuario6.id        ="R126";
//    miUsuario6.nombre    ="romario";
//    miUsuario6.telefono  ="40589467";

//    Usuario miUsuario7;
//    miUsuario7.direccion ="12av13-64 Ramirez";
//    miUsuario7.id        ="R127";
//    miUsuario7.nombre    ="prueba";
//    miUsuario7.telefono  ="40589467";

//    Usuario miUsuario8;
//    miUsuario8.direccion ="12av13-64 Ramirez";
//    miUsuario8.id        ="R128";
//    miUsuario8.nombre    ="iphone";
//    miUsuario8.telefono  ="40589467";

//    Usuario miUsuario9;
//    miUsuario9.direccion ="12av13-64 Ramirez";
//    miUsuario9.id        ="R129";
//    miUsuario9.nombre    ="xiomara";
//    miUsuario9.telefono  ="40589467";

//    ListaUsuario* milista = new ListaUsuario();
//    milista->insertar(miUsuario1);
//    milista->insertar(miUsuario2);
//    milista->insertar(miUsuario3);
//    milista->insertar(miUsuario4);
//    milista->insertar(miUsuario5);
//    milista->insertar(miUsuario6);
//    milista->insertar(miUsuario7);
//    milista->insertar(miUsuario8);
//    milista->insertar(miUsuario9);

//    milista->imprimirLista();


//    milista->eliminar(miUsuario9.id);
//    milista->eliminar(miUsuario1.id);
//    milista->eliminar(miUsuario8.id);

//    milista->imprimirLista();

//    milista->graficar();


//    ListaTratamiento* milistTrat = new ListaTratamiento();

//    milistTrat->insertar({"ads1","JUanita1","tos"});
//    milistTrat->insertar({"ads2","JUanita2","tos"});
//    milistTrat->insertar({"ads3","JUanita3","tos"});
//    milistTrat->insertar({"ads4","JUanita4","tos"});
//    milistTrat->insertar({"ads5","JUanita5","tos"});
//    milistTrat->insertar({"ads6","JUanita6","tos"});
//    milistTrat->insertar({"ads7","JUanita7","tos"});

//    milistTrat->imprimirLista();

//    milistTrat->graficar();


//    struct Cita
//    {
//        std::string transaccion;
//        std::string tratamiento;
//        std::string idUsuario;
//        std::string  estado;
//    };

//    struct Hora
//    {
//        std::string horaInicio;
//        std::string horaFin;
//    };

//    struct Dia
//    {
//        std::string diaString;
//        int diaEntero;
//    };

//    NodoOrtogonal(Cita cita,Hora fila, Dia col);




    ListaFila* milistFila = new ListaFila();

NodoOrtogonal* nuevo1 = new NodoOrtogonal({"Transaccion1","tratamiento1","idUsuario1","estado1"},{"8:00","9:00"},{"Martes",2});
NodoOrtogonal* nuevo2 = new NodoOrtogonal({"Transaccion2","tratamiento1","idUsuario1","estado1"},{"8:00","9:00"},{"Miercoles",3});
NodoOrtogonal* nuevo3 = new NodoOrtogonal({"Transaccion3","tratamiento1","idUsuario1","estado1"},{"8:00","8:30"},{"Jueves",4});
NodoOrtogonal* nuevo4 = new NodoOrtogonal({"Transaccion4","tratamiento1","idUsuario1","estado1"},{"9:00","11:00"},{"Miercoles",3});
NodoOrtogonal* nuevo5 = new NodoOrtogonal({"Transaccion5","tratamiento1","idUsuario1","estado1"},{"8:00","9:00"},{"Lunes",1});
NodoOrtogonal* nuevo6 = new NodoOrtogonal({"Transaccion6","tratamiento1","idUsuario1","estado1"},{"6:00","9:00"},{"Lunes",1});


    std::string respuesta1 = milistFila->insertar(nuevo1);
    std::string respuesta2 = milistFila->insertar(nuevo2);
    std::string respuesta3 = milistFila->insertar(nuevo3);
    std::string respuesta4 = milistFila->insertar(nuevo4);
    std::string respuesta5 = milistFila->insertar(nuevo5);
    std::string respuesta6 = milistFila->insertar(nuevo6);



    std::cout<<"["<<respuesta1<<"]"<<std::endl;
    std::cout<<"["<<respuesta2<<"]"<<std::endl;
    std::cout<<"["<<respuesta3<<"]"<<std::endl;
    std::cout<<"["<<respuesta4<<"]"<<std::endl;
    std::cout<<"["<<respuesta5<<"]"<<std::endl;
    std::cout<<"["<<respuesta6<<"]"<<std::endl;

    std::cout<<"["<<milistFila->ultimo->listHorizontal->ultimoFila->getCita().transaccion<<"]"<<std::endl;






      return (0);
    }



