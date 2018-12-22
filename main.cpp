#include <iostream>
#include <Lista.h>



int main() {

    Usuario miUsuario1;
    miUsuario1.direccion ="12av13-64 Ramirez";
    miUsuario1.id        ="R123";
    miUsuario1.nombre    ="Juanito";
    miUsuario1.telefono  ="40589467";

    Usuario miUsuario2;
    miUsuario2.direccion ="12av13-64 Ramirez";
    miUsuario2.id        ="R123";
    miUsuario2.nombre    ="Omar";
    miUsuario2.telefono  ="40589467";

    ListaUsuario* milista = new ListaUsuario();
    milista->insertar(miUsuario1);
    milista->insertar(miUsuario2);



  return (0);
}



