#include <iostream>

using namespace std;
#include "Clases.h"




void menuRRHH(){
    while (true) {
             int anchoPantalla = 80, opc;

     string encabezado = "MENU RRHH";
     string opcion1 = "1. AGREGAR NUEVO RRHH";
     string opcion2 = "2. AGREGAR NUEVO SUPERVISOR";
     string opcion3 = "3. AGREGAR NUEVO ENCARGADO";
     string opcion4 = "4. AGREGAR NUEVO OPERARIO";
     string opcion5 = "5. MOSTRAR TODO EL PERSONAL";
     string opcion6 = "6. SALIR";

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

     cout<<"\n \n \n \n \n \n";
     cout<< setw (79)<< setfill('*')<<"*"<<endl;
      cout << setfill(' ');
        cout << setw(0);


        cin>>opc;
        system("cls");
        RRHH nuevoRRHH;
        Supervisor nuevoSupervisor;
        system("cls");
        switch (opc){
        case 1:
            nuevoRRHH.cargarPersonal();
            if(ficheroJefes.grabarenArchivoJefes(&nuevoRRHH))
                cout<<"\n CARGADO EXITOSAMENTE "; limpiarPantalla();
            break;
        case 2:  nuevoSupervisor.cargarPersonal();
                if(ficheroJefes.grabarenArchivoJefes(&nuevoSupervisor))
                cout<<"\n CARGADO EXITOSAMENTE"; limpiarPantalla();
            break;
        case 3: agregarEncargado();
            break;
        case 4: agregarOperario();
            break;
        case 5: mostrarTodo();
            break;
        case 6: return;
            break;

        default: cout<<"VALOR NO VALIDO, INGRESE OTRO\n";
           break;
        }

    }
}
///3
void agregarEncargado(){
    Encargado nuevoEncargado;
    bool existe=true;
    nuevoEncargado.cargarPersonal();
     int numero=nuevoEncargado.getTurno();
    while(existe) {
          for(int i=0; i<3; i++) {
            if(15==numero){
            cout<<"EL TURNO YA ESTA OCUPADO, INGRESE OTRO O DE LA BAJA DEL ENCARGADO A REEMPLAZAR";
            cin>>numero;
            existe=true;
            break;}
            existe=false;
          }}
    nuevoEncargado.setTurno(numero);
    if(ficheroJefes.grabarenArchivoJefes(&nuevoEncargado)) {
     cout<<"\n CARGADO EXITOSAMENTE";}
}
///4
void agregarOperario() {
    Operario nuevoOperario;
    nuevoOperario.cargarOperario();
    ficheroOperarios.grabarOperario(&nuevoOperario);
}

///5
void mostrarTodo(){
    cout<<"PERSONAL JERARQUICO: \n\n";
    Personal* miPersonal;  // Inicializar con nullptr;
    int cantidadJefes = ficheroJefes.contarRegistrosArchivoJefes(miPersonal);


    imprimirEncabezado("ROL", "NOMBRE", "APELLIDO", "DNI", "LEGAJO", "ANTIGUEDAD");
   for(int i=0; i<cantidadJefes; i++) {
    miPersonal = ficheroJefes.leerRegistroArchivoJefes(i);
    if (miPersonal != nullptr) {
        miPersonal->mostrarPersonal();
        delete miPersonal;
    } else {
        cout << "Error al leer el registro en la posición " << i << " del archivo de Jefes.\n";
    }
}
    cout<<"\n \n \n OPERARIOS \n\n";

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
    system("pause");
    system("cls");
}


