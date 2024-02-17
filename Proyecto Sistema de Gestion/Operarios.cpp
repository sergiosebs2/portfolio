#include <iostream>
using namespace std;
#include "Prototipos.h"

void menuOperarios(){
    while (true) {
                   int anchoPantalla = 80, opc;

     string encabezado = "MENU OPERARIOS";
     string opcion1 = "1. VER PEDIDOS ASIGNADOS";
     string opcion2 = "2. CARGAR PRODUCCION";
     string opcion3 = "3. VER COMENTARIOS RECIBIDOS";
     string opcion4 = "4. DEJAR COMENTARIO A ENCARGADO";
     string opcion5 = "5. SALIR";

     cout<<internal;
     cout<< setw (79)<< setfill('*')<<"*"<<endl;
     cout<<"\n \n \n \n \n \n \n";
     cout <<  setw((anchoPantalla + encabezado.length()) / 2) << setfill(' ') << encabezado << endl << endl;
     cout <<  setw((anchoPantalla + opcion1.length()) / 2) << setfill(' ') << opcion1 << endl;
     cout <<  setw((anchoPantalla + opcion2.length()) / 2) << setfill(' ') << opcion2 << endl;
     cout <<  setw((anchoPantalla + opcion3.length()) / 2) << setfill(' ') << opcion3 << endl;
     cout <<  setw((anchoPantalla + opcion4.length()) / 2) << setfill(' ') << opcion4 << endl;
     cout <<  setw((anchoPantalla + opcion5.length()) / 2) << setfill(' ') << opcion5 << endl;
     cout<<"\n \n \n \n \n \n";
     cout<< setw (79)<< setfill('*')<<"*"<<endl;

        cin>>opc;
        system("cls");
        switch (opc){
        case 1: verPedidos(); limpiarPantalla();
            break;
        case 2: verPedidos(1);
            break;
        case 3: verComentariosdeEncargados(); limpiarPantalla();
            break;
        case 4: enviarComentarioaEncargado(); limpiarPantalla();
            break;
        case 5: return;
            break;

        default: cout<<"VALOR NO VALIDO, INGRESE OTRO\n";
           break;
        }

    }
}

void verPedidos(int cargar){

    int numero, cantidadPedidos, cantidadOperarios;
    cout<<"\n INGRESE EL LEGAJO DE OPERARIO PARA VER LOS PEDIDOS ASIGNADOS: ";
    cin>> numero;
    Operario* nuevoOperario;
    Pedidos* nuevoPedido;

    cantidadOperarios = ficheroOperarios.contarRegistrosOperarios(nuevoOperario);
    for(int i=0; i<cantidadOperarios; i++) {
        nuevoOperario = ficheroOperarios.leerRegistroOperarios(i);
        if(nuevoOperario->getLegajo()==numero) break;
    }

            cantidadPedidos= pedidosenProceso.contarRegistrosPedidosenProceso(nuevoPedido);
            for(int j=0; j<cantidadPedidos; j++) {
                nuevoPedido = pedidosenProceso.leerRegistroPedidosenProceso(j);
                        if(nuevoPedido->getAsignacion()==numero){

                        cout<<" \n \n PEDIDOS ASOCIADOS AL OPERARIO DE LEGAJO:  "<<numero<<"\n\n";

                                imprimirEncabezado("MEDIDA", "NOMBRE", "PROVEEDOR", "CODIGO", "TRATADO", "CANTIDAD");
                                nuevoPedido->mostrarPedido();
                                cout<<"\n\n\n";
                                }
                                else if(j==(cantidadPedidos-1)) cout<<"\n\n NO HAY PEDIDOS ASIGNADOS A ESE NUMERO DE OPERARIO \n\n";

                            ///CARGAR
                            if(cargar==1) {
                                char contra[30];
                                cout<<"\n BIENVENIDO/A "<<nuevoOperario->getNombre()<<", PARA PODER CARGAR, INGRESE SU CONTRASENIA: ";
                                cin>>contra;
                                    while (strcmp((nuevoOperario->getContrasenia()), contra)!=0) {
                                        cout<<"\n CONTRASEÑA ERRONEA, INGRESE NUEVAMETE (ES SU NOMBRE): ";
                                        cargarCadena(contra, 29);
                                    }
                                cout<<"\n INGRESE LA CANTIDAD REALIZADA: ";
                                cin>>numero;
                                nuevoPedido->setCantidad((nuevoPedido->cantidadRestante())-numero);
                                if(pedidosenProceso.grabarPedidoModificado(nuevoPedido, j)) cout<<"\n \n GRABADO CORRECTAMENTE";
                                    break;

                            }
                            }
                            limpiarPantalla();
}




void verComentariosdeEncargados(){
    mostrarMensaje(canalUno);

}
void enviarComentarioaEncargado(){

    escribirMensaje(canalDos);

}
