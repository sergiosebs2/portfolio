#include <iostream>

using namespace std;
#include "Prototipos.h"

void menuSupervisor(){
    while (true) {
      int anchoPantalla = 80, opc;

     string encabezado = "MENU SUPERVISOR";
     string opcion1 = "1. MOSTRAR PEDIDOS EN PROCESO";
     string opcion2 = "2. AGREGAR NUEVO PEDIDO EN PROCESO";
     string opcion3 = "3. TERMINAR PEDIDO EN PROCESO";
     string opcion4 = "4. AGREGAR NUEVO PEDIDO A LA BASE DE DATOS";
     string opcion5 = "5. MOSTRAR HISTORIAL PEDIDOS TERMINADOS";
     string opcion6 = "6. SALIR";

     cout<<internal;
     cout<< setw (79)<< setfill('*')<<"*"<<endl;
     cout<<"\n \n \n \n \n \n \n ";
     cout <<  setw((anchoPantalla + encabezado.length()) / 2) << setfill(' ') << encabezado << endl << endl;
     cout <<  setw((anchoPantalla + opcion1.length()) / 2) << setfill(' ') << opcion1 << endl;
     cout <<  setw((anchoPantalla + opcion2.length()) / 2) << setfill(' ') << opcion2 << endl;
     cout <<  setw((anchoPantalla + opcion3.length()) / 2) << setfill(' ') << opcion3 << endl;
     cout <<  setw((anchoPantalla + opcion4.length()) / 2) << setfill(' ') << opcion4 << endl;
     cout <<  setw((anchoPantalla + opcion5.length()) / 2) << setfill(' ') << opcion5 << endl;
     cout <<  setw((anchoPantalla + opcion6.length()) / 2) << setfill(' ') << opcion6 << endl;
     cout<<"\n \n \n \n \n \n \n";
     cout<< setw (79)<< setfill('*')<<"*"<<endl;
     cout << setfill(' ');
     cout << setw(0);

        cin>>opc;
        system("cls");
        switch (opc){
        case 1: mostrarPedidosenProceso(); limpiarPantalla();
            break;
        case 2: agregarPedidoenProceso(); limpiarPantalla();
            break;
        case 3: terminarPedidoEnProceso(); limpiarPantalla();
            break;
        case 4: agregarPedidoenBasedeDatos();
            break;
        case 5: mostrarPedidosTerminados(); limpiarPantalla();
            break;
        case 6: return;
            break;

        default: cout<<"VALOR NO VALIDO, INGRESE OTRO\n";
           break;
        }

    }
}
void mostrarPedidosenProceso() {

    Pedidos* nuevoPedido;
    int cantidad = pedidosenProceso.contarRegistrosPedidosenProceso(nuevoPedido);
    imprimirEncabezado("MEDIDA", "NOMBRE", "PROVEEDOR", "CODIGO", "TRATADO", "CANTIDAD");
    for (int i=0; i<cantidad; i++) {
                nuevoPedido = pedidosenProceso.leerRegistroPedidosenProceso(i);
                 if (nuevoPedido != nullptr && (!nuevoPedido->getEstado())) {
                            nuevoPedido->mostrarPedido();
                            delete nuevoPedido;    }
                    }
    cout<<"\n\n";


}
void mostrarListaTodoslosPedidos() {

    Pedidos* nuevoPedido;
    int cantidad = todoslosPedidos.contarRegistrosTodoslosPedidos(nuevoPedido);
    imprimirEncabezado("MEDIDA", "NOMBRE", "PROVEEDOR", "CODIGO", "TRATADO", "CANTIDAD");
    for (int i=0; i<cantidad; i++) {
                nuevoPedido = todoslosPedidos.leerRegistroTodoslosPedidos(i);
                if (nuevoPedido != nullptr) {
                            nuevoPedido->mostrarPedido();
                            delete nuevoPedido;    }
                    }
    cout<<"\n\n";
}
void agregarPedidoenProceso() {
    int eleccion, cantidad;
    Pedidos* nuevoPedido;
    mostrarListaTodoslosPedidos();
    cout<<"\n\n\n INGRESE EL CODIGO DEL PEDIDO A AGREGAR: ";
    cin>> eleccion;

    cantidad = todoslosPedidos.contarRegistrosTodoslosPedidos(nuevoPedido);
    for (int i=0; i<cantidad; i++) {
                nuevoPedido = todoslosPedidos.leerRegistroTodoslosPedidos(i);
                if(nuevoPedido->getCodigo()==eleccion) {
                    if(pedidosenProceso.grabarenPedidosenProceso(nuevoPedido)) {
                        cout<<"\n CARGADO EXITOSAMENTE";
                        break;
                    }


    }}

}
void agregarPedidoenBasedeDatos(){
        Pedidos nuevoPedido;
        nuevoPedido.agregarPedido();

        if(todoslosPedidos.grabarenTodoslosPedidos(&nuevoPedido)) cout<<"\n CARGADO EXITOSAMENTE \n";
        limpiarPantalla();
}

void terminarPedidoEnProceso() {

    mostrarPedidosenProceso();
    Pedidos* nuevoPedido;
    int cantidad = pedidosenProceso.contarRegistrosPedidosenProceso(nuevoPedido);
    for (int i=0; i<cantidad; i++) {
                nuevoPedido = pedidosenProceso.leerRegistroPedidosenProceso(i);
                if(nuevoPedido->cantidadRestante()==0 && !(nuevoPedido->getEstado())) {
                    cout<<"DESEA TERMINAR EL PEDIDO: "<<nuevoPedido->getCodigo()<<" ?\n 1- TERMINAR \n 2- NO TERMINAR\n\n";
                    cin>> cantidad;
                        if(cantidad==1) {
                                nuevoPedido->terminarPedido();
                                if(pedidosenProceso.grabarPedidoModificado(nuevoPedido, i)){ cout<<"\n FINALIZADO CON EXITO!";}
                        }
                }
    }
}


void mostrarPedidosTerminados() {

    Pedidos* nuevoPedido;
    int cantidad = pedidosenProceso.contarRegistrosPedidosenProceso(nuevoPedido);
    imprimirEncabezado("CODIGO", "NOMBRE", "PROVEEDOR", "MEDIDA", "TRATADO", "CANTIDAD");
    for (int i=0; i<cantidad; i++) {
                nuevoPedido = pedidosenProceso.leerRegistroPedidosenProceso(i);
                 if (nuevoPedido != nullptr && ((nuevoPedido->getEstado()))) {
                            nuevoPedido->mostrarPedido();
                            delete nuevoPedido;    }
                    }
    cout<<"\n\n";
}


