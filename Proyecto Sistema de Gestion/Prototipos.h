#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED



//MENUES

void menuOperarios();
void menuEncargados();
void menuSupervisor();
void menuRRHH();

//RRHH
void agregarRRHH();
void agregarSupervisor();
void agregarEncargado();
void agregarOperario();
void mostrarTodo();


//SUPERVISOR
void mostrarPedidosenProceso();
void agregarPedidoenProceso();
void agregarPedidoenBasedeDatos();
void mostrarListaTodoslosPedidos();
void terminarPedidoEnProceso();
void mostrarPedidosTerminados();


//ENCARGADOS
void mostrarEncargados();
void mostrarOperarios();
void asignarPedido();
void enviarMensajeaOperario();
void leerMensajedeOperario();
void revisarPedidosTratamientoTerminados();


//OPERARIO
void verPedidos(int cargar=0);
void verMensajes();
void verComentariosdeEncargados();
void enviarComentarioaEncargado();

///FUNCIONES GLOBALES

bool grabarRegistro(const void *reg, size_t size, const char *nombrearchivo, int pos=-1);
int contarRegistros (const char *nombrearchivo, size_t sizeRegistro);
template <typename T>
T* leerRegistro(T* reg, int pos, const char* nombreArchivo, size_t size);
void imprimirTabla(const string& columna1, const string& columna2, const string& columna3, int columna4, int columna5, int columna6);
void imprimirEncabezado(const string& columna1,const string& columna2,const string& columna3,const string& columna4,const string& columna5,const string& columna6);


#endif // PROTOTIPOS_H_INCLUDED
