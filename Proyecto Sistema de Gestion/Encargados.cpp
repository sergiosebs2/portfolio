#include <iostream>
using namespace std;
#include "Prototipos.h"

void menuEncargados(){
    while (true) {
                     int anchoPantalla = 80, opc;

     string encabezado = "MENU ENCARGADOS";
     string opcion1 = "1. MOSTRAR ENCARGADOS ACTUALES";
     string opcion2 = "2. MOSTRAR OPERARIOS ACTUALES";
     string opcion3 = "3. MOSTRAR PEDIDOS ACTUALES";
     string opcion4 = "4. ASIGNAR PEDIDO";
     string opcion5 = "5. REVISAR PEDIDOS CON TRATAMIENTO TERMINADOS";
     string opcion6 = "6. ENVIAR COMENTARIOS A OPERARIO";
     string opcion7 = "7. LEER COMENTARIOS DE ENCARGADO";
     string opcion8 = "8. SALIR";

     cout<<internal;
     cout<< setw (79)<< setfill('*')<<"*"<<endl;
     cout<<"\n \n \n \n \n \n \n";
     cout <<  setw((anchoPantalla + encabezado.length()) / 2) << setfill(' ') << encabezado << endl << endl;
     cout <<  setw((anchoPantalla + opcion1.length()) / 2) << setfill(' ') << opcion1 << endl;
     cout <<  setw((anchoPantalla + opcion2.length()) / 2) << setfill(' ') << opcion2 << endl;
     cout <<  setw((anchoPantalla + opcion3.length()) / 2) << setfill(' ') << opcion3 << endl;
     cout <<  setw((anchoPantalla + opcion4.length()) / 2) << setfill(' ') << opcion4 << endl;
     cout <<  setw((anchoPantalla + opcion5.length()) / 2) << setfill(' ') << opcion5 << endl;
     cout <<  setw((anchoPantalla + opcion6.length()) / 2) << setfill(' ') << opcion6 << endl;
     cout <<  setw((anchoPantalla + opcion7.length()) / 2) << setfill(' ') << opcion7 << endl;
     cout <<  setw((anchoPantalla + opcion8.length()) / 2) << setfill(' ') << opcion8 << endl;
     cout<<"\n \n \n \n \n \n";
     cout<< setw (79)<< setfill('*')<<"*"<<endl;

        cin>>opc;
        system("cls");
        switch (opc){
        case 1: mostrarEncargados();
            break;
        case 2: mostrarOperarios(); limpiarPantalla();
            break;
        case 3: mostrarPedidosenProceso(); limpiarPantalla();
            break;
        case 4: asignarPedido(); limpiarPantalla();
            break;
        case 5: revisarPedidosTratamientoTerminados();
            break;
        case 6: enviarMensajeaOperario(); limpiarPantalla();
            break;
        case 7: leerMensajedeOperario(); limpiarPantalla();
            break;
        case 8: return;
            break;

        default: cout<<"VALOR NO VALIDO, INGRESE OTRO\n";
           break;
        }

    }
}

void mostrarEncargados(){

    Personal* miPersonal;
    int cantidadJefes = ficheroJefes.contarRegistrosArchivoJefes(miPersonal);


    imprimirEncabezado("ROL", "NOMBRE", "APELLIDO", "DNI", "LEGAJO", "ANTIGUEDAD");
    for(int i=0; i<cantidadJefes; i++) {
        miPersonal = ficheroJefes.leerRegistroArchivoJefes(i);
        if (miPersonal != nullptr) {
                if(strcmp((miPersonal->getRol()), "ENCARGADO") == 0){
                miPersonal->mostrarPersonal();
                delete miPersonal;}
        } else {
        cout << "Error al leer el registro en la posición " << i << " del archivo de Jefes.\n";
    }
}   cout<<"\n \n";
    system("pause");
    system("cls");
}

void mostrarOperarios(){
        Operario* miOperario= nullptr;
    int cantidadOps = ficheroOperarios.contarRegistrosOperarios(miOperario);
    imprimirEncabezado("SECTOR", "NOMBRE", "APELLIDO", "DNI", "LEGAJO", "ANTIGUEDAD");
    for(int i=0; i<cantidadOps; i++) {
        miOperario = ficheroOperarios.leerRegistroOperarios(i);
            if(miOperario!= nullptr) {
                miOperario->mostrarOperarios();
                delete miOperario;}
             else cout<< "Error al leer el registro en la posición " << i;
    }
    cout<<"\n \n \n";


}
void asignarPedido(){
    int pedido, opAsignado;
    mostrarPedidosenProceso();
    cout<<"INGRESE EL CODIGO DEL PEDIDO A ASIGNAR \n\n";
    cin>> pedido;
    mostrarOperarios();
    cout<<"\n\nRECUERDE QUE SI LLEVA TRATADO, DEBE ELEGIR UN OPERARIO DE SECTOR B PRIMERO, \nINGRESE EL LEGAJO DEL OPERARIO AL CUAL DESEA ASIGNARLE EL PEDIDO: ";
    cin>> opAsignado;

    Pedidos* nuevoPedido;
    int cantidad= pedidosenProceso.contarRegistrosPedidosenProceso(nuevoPedido);

    for (int i=0; i<cantidad; i++) {
        nuevoPedido = pedidosenProceso.leerRegistroPedidosenProceso(i);
            if(nuevoPedido->getCodigo()==pedido) {
                nuevoPedido->setAsigacion(opAsignado);

                if(pedidosenProceso.grabarPedidoModificado(nuevoPedido, i)) cout<<"\n\n ASIGNADO CON EXITO \n\n";
                break;
            }

    }

limpiarPantalla();
}


void revisarPedidosTratamientoTerminados() {
    Pedidos* nuevoPedido;
    int numero, codigo, cantidad = pedidosenProceso.contarRegistrosPedidosenProceso(nuevoPedido);
    imprimirEncabezado("MEDIDA", "NOMBRE", "PROVEEDOR", "CODIGO", "TRATAMIENTO", "CANTIDAD");
    for (int i=0; i<cantidad; i++) {
                nuevoPedido = pedidosenProceso.leerRegistroPedidosenProceso(i);
                 if (nuevoPedido != nullptr && (!nuevoPedido->getEstado())) {
                            if(nuevoPedido->getTipodePedido()==2 && nuevoPedido->cantidadRestante()==0) {
                                nuevoPedido->mostrarPedido();
                                delete nuevoPedido;    }
                                else if(i==(cantidad-1)) {
                                        cout<<"\n\n NO HAY NINGUN PEDIDO PARA TERMINAR \n\n";
                                        limpiarPantalla(); return; }
                    } }
    cout<<"\n\n INGRESE EL CODIGO DE PEDIDO A PASAR AL SECTOR 1: ";
    cin>>codigo;
    cout<<"\n \n INGRESE LA CANTIDAD DE PRODUCTO PEDIDA: ";
    cin>>numero;

    for (int i=0; i<cantidad; i++) {
                nuevoPedido = pedidosenProceso.leerRegistroPedidosenProceso(i);
                 if (nuevoPedido != nullptr && (!nuevoPedido->getEstado())) {
                            if(nuevoPedido->getCodigo()==codigo) {
                                nuevoPedido->setCantidad(numero);
                                nuevoPedido->pasarASector1();
                                delete nuevoPedido;    }
                    }

system("pause");
}
}

void enviarMensajeaOperario(){
    escribirMensaje(canalUno);

}

void leerMensajedeOperario(){

    mostrarMensaje(canalDos);

}
