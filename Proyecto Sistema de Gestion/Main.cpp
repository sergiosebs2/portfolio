#include <iostream>
#include <string.h>
#include <iomanip>
#include <limits>
using namespace std ;

#include "Prototipos.h"
#include "FuncionesGlobales.cpp"
#include "Clases.h"


///DECLARACION DE ARCHIVOS;

ArchivoOperarios ficheroOperarios("ListadeOperarios.dat");
ArchivoPedidos todoslosPedidos("ListadetodoslosPedidos.dat");
ArchivoPedidos pedidosenProceso("ListadePedidosenProceso.dat");
ArchivoJefes ficheroJefes("ListadeJefes.dat");
char* canalUno = nullptr;
char* canalDos = nullptr;

#include "RecursosHumanos.cpp"
#include "Encargados.cpp"
#include "Operarios.cpp"
#include "Supervisor.cpp"



int main() {

     int anchoPantalla = 80, opc;

    string encabezado = "MENU PRINCIPAL";
    string opcion1 = "1. MENU OPERARIOS";
    string opcion2 = "2. MENU ENCARGADOS";
    string opcion3 = "3. MENU SUPERVISOR";
    string opcion4 = "4. MENU RRHH";
    string opcion5 = "5. SALIR";

    while (true) {
             cout << setfill(' ');
        cout<<internal;
        cout << setw(0);
        cout << string(anchoPantalla, '*') << endl;
        cout << "\n \n \n \n \n \n \n";
        cout << setw((anchoPantalla + encabezado.length()) / 2) << encabezado << endl << endl;
        cout << setw((anchoPantalla + opcion1.length()) / 2) << opcion1 << endl;
        cout << setw((anchoPantalla + opcion2.length()) / 2) << opcion2 << endl;
        cout << setw((anchoPantalla + opcion3.length()) / 2) << opcion3 << endl;
        cout << setw((anchoPantalla + opcion4.length()) / 2) << opcion4 << endl;
        cout << setw((anchoPantalla + opcion5.length()) / 2) << opcion5 << endl;
        cout << "\n \n \n \n \n \n";
        cout << string(anchoPantalla, '*') << endl;


        cin>>opc;
        system("cls");
        switch (opc){
        case 1: menuOperarios();
            break;
        case 2: menuEncargados();
            break;
        case 3: menuSupervisor();
            break;
        case 4: menuRRHH();
            break;
        case 5: return 0;
            break;

        default: cout<<"VALOR NO VALIDO, INGRESE OTRO\n";
           break;
        }
    }

}
