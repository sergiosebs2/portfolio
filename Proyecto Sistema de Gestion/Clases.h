#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED

#include <string.h>


void cargarCadena(char *palabra, int tam){
    int i = 0;
    fflush(stdin);
    for (i = 0 ; i < tam ; i++ )
    {
        palabra[i] = cin.get();
        if(palabra[i] == '\n') break;
    }
    palabra[i] = '\0';
    fflush(stdin);
}


class Personal {
    protected:
        char nombre[30], apellido[30], contrasenia[30], rol[30];
        int DNI, turno, legajo, antiguedad;
        bool estado=true;
    public:
        void cargarPersonal() {
            cout<<"\n ROL: ";
            cargarCadena(rol, 29);
            cout<<"\n NOMBRE: ";
            cargarCadena(nombre, 29);
            strncpy(contrasenia, nombre, sizeof(nombre));
            cout<<"\n APELLIDO: ";
            cargarCadena (apellido,29);
            cout<<"\n DNI: ";
            cin>>DNI;
            cout<<"\n LEGAJO: ";
            cin>>legajo;
            cout<<"\n ANTIGUEDAD: ";
            cin>> antiguedad;
            cout<<"\n INGRESE TURNO (DEBE SER 1,2 o 3): ";
            cin>> turno;

            }
        void mostrarPersonal() {
                imprimirTabla(rol, nombre, apellido, DNI, legajo, antiguedad);
        }
            int getTurno(){return turno;}
            void setTurno(int nuevo) {turno=nuevo;}
            const char* getRol() {return rol;}
            const char* getNombre(){return nombre;}

};
class RRHH: public Personal {
public:
   void setContrasenia(const char *palabra) { strcpy(contrasenia, palabra); }
   void setEstado (bool determinar) {estado = determinar;}

};
class Supervisor: public Personal {

public:

};
class Encargado : public Personal {
private:

public:

};
class Operario : public Personal {
    private:
        char sector[10];
    public:
        void cargarOperario(){
            cargarPersonal();
            cout<<"INGRESE SECTOR(A o B): ";
            cargarCadena(sector, 9);}
        const char* getContrasenia(){return contrasenia;}
        int getLegajo(){return legajo;}
        void mostrarOperarios() {imprimirTabla(sector, nombre, apellido, DNI, legajo, antiguedad);}

};

class Pedidos {
    private:
        char nombrePedido [30],nombreProveedor [30], medidaPedido [30];
        int tipodePedido, cantidadPedida, codigoPedido, asignacion=0;
        bool terminar = false;

    public:
        int getCodigo() {return codigoPedido;}
        int cantidadRestante(){return cantidadPedida;}
        bool getEstado(){return terminar;}
        void terminarPedido() {terminar= true;}
        void setAsigacion(int numero){asignacion=numero;}
        int getAsignacion(){return asignacion;}
        int getTipodePedido(){return tipodePedido;}
        void setCantidad(int numero){cantidadPedida= numero; }
        void pasarASector1(){tipodePedido=1;}

        void agregarPedido(){
            cout<<"INGRESE EL NOMBRE DEL PEDIDO: ";
            cargarCadena(nombrePedido, 29);
            cout<<"\n INGRESE EL CODIGO DEL PEDIDO: ";
            cin>>codigoPedido;
            cout<<"\n INGRESE EL NOMBRE DEL PROVEEDOR: ";
            cargarCadena(nombreProveedor, 29);
            cout<<"\n INGRESE LA MEDIDA DEL PRODUCTO PEDIDO: ";
            cargarCadena(medidaPedido, 29);
            cout<<"\n INGRESE EL TIPO DE PEDIDO (SI LLEVA TRATAMIENTO INGRESE 2):";
            cin>> tipodePedido;
            cout<<"\n INGRESE CANTIDAD PEDIDA: ";
            cin>> cantidadPedida;

        }
        void mostrarPedido() {

            imprimirTabla(medidaPedido, nombrePedido, nombreProveedor,codigoPedido , tipodePedido, cantidadPedida);
        }
};
/// ARCHIVOS

class ArchivoOperarios {
    private:
        char nombre[30];
    public:
        ArchivoOperarios(const char *n){
            strcpy(nombre,n);}

        /*bool grabarOperario(const Operario *reg) {
            return grabarRegistro(reg, "ListadeOperarios.dat");
        }*/
        bool grabarOperario(const Operario *reg) {
    return grabarRegistro(reg, sizeof(Operario), "ListadeOperarios.dat");
}

        Operario* leerRegistroOperarios(int pos) {
            Operario* reg = new Operario();
            return leerRegistro(reg, pos, "ListadeOperarios.dat", sizeof(Operario));
}

        int contarRegistrosOperarios (Operario *reg){
            return contarRegistros("ListadeOperarios.dat", sizeof(Operario));
        }

};
class ArchivoPedidos {
private:
  char nombre[30];
public:
    ArchivoPedidos(const char *n) {
    strcpy(nombre, n);}

    bool grabarenTodoslosPedidos(const Pedidos *reg) {
            return grabarRegistro(reg, sizeof(Pedidos),"ListadetodoslosPedidos.dat");
        }

    Pedidos* leerRegistroTodoslosPedidos(int pos) {
            Pedidos* reg = new Pedidos();
            return leerRegistro(reg, pos, "ListadetodoslosPedidos.dat", sizeof(Pedidos));
        }

    int contarRegistrosTodoslosPedidos (Pedidos *reg){
            return contarRegistros("ListadetodoslosPedidos.dat", sizeof(Pedidos));
        }
    bool grabarenPedidosenProceso(const Pedidos *reg) {
            return grabarRegistro(reg, sizeof(Pedidos), "ListadePedidosenProceso.dat");
        }

    Pedidos* leerRegistroPedidosenProceso(int pos) {
            Pedidos* reg = new Pedidos();
            return leerRegistro(reg, pos, "ListadePedidosenProceso.dat", sizeof(Pedidos));
        }

    int contarRegistrosPedidosenProceso (Pedidos *reg){
            return contarRegistros("ListadePedidosenProceso.dat", sizeof(Pedidos));
        }
    bool grabarPedidoModificado(const Pedidos *reg, int pos) {
            return grabarRegistro(reg, sizeof(Pedidos), "ListadePedidosenProceso.dat", pos);
        }

};

class ArchivoJefes {
private:
    char nombre[30];
public:
    ArchivoJefes(const char *n) {
    strcpy(nombre, n);}

    bool grabarenArchivoJefes(const Personal *reg) {
            return grabarRegistro(reg, sizeof(Personal), "ListadeJefes.dat");
        }

    Personal* leerRegistroArchivoJefes(int pos) {
        Personal* reg = new Personal();
        return leerRegistro(reg, pos, "ListadeJefes.dat",sizeof(Personal));
}

    int contarRegistrosArchivoJefes (Personal *reg){
            return contarRegistros("ListadeJefes.dat", sizeof(Personal));
        }
    };
#endif // CLASES_H_INCLUDED
