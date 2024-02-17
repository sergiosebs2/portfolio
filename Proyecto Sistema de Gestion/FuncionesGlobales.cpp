#include<iostream>
#include<cstdlib>
#include <string.h>

using namespace std;
#include "Prototipos.h"

#include "Clases.h"

void limpiarPantalla(){
    cout<<"\n \n"; system("pause"); system("cls");
}


template <typename T>
T* leerRegistro(T* reg, int pos, const char* nombreArchivo, size_t size) {
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == NULL) {
        cout << "Error al abrir el archivo " << nombreArchivo << " para lectura.\n";
        return nullptr;
    }

    fseek(p, size * pos, SEEK_SET);
    size_t bytesRead = fread(reg, size, 1, p);
    fclose(p);

    if (bytesRead != 1) {
        cout << "Error al leer el registro en la posición " << pos << ". Bytes leídos: " << bytesRead << "\n";
        return nullptr;
    }

    return reg;
}
int contarRegistros(const char *nombrearchivo, size_t sizeRegistro) {
    FILE *p = fopen(nombrearchivo, "rb");
    if (p == NULL) {
        cout << "Error al abrir el archivo " << nombrearchivo << " para contar registros.\n";
        return -1;
    }

    fseek(p, 0, SEEK_END);
    int tamTotal = ftell(p);
    fclose(p);

    if (tamTotal == 0) {
        // El archivo está vacío
        return 0;
    }

    return tamTotal / sizeRegistro;
}



    bool grabarRegistro(const void *reg, size_t size, const char *nombrearchivo) {
    FILE *p;
    p = fopen(nombrearchivo, "ab");
    if (p == NULL) return false;

    bool escribio = fwrite(reg, size, 1, p) == 1;

    fclose(p);
    return escribio;
}
bool grabarRegistro(const void *reg, size_t size, const char *nombrearchivo, int pos) {
    FILE *p;
    p = fopen(nombrearchivo, "r+b");
    if (p == NULL) return false;

    if (pos != -1) {
        fseek(p, size * pos, SEEK_SET);
    } else {
        fseek(p, 0, SEEK_END);
    }

    bool escribio = fwrite(reg, size, 1, p) == 1;

    fclose(p);
    return escribio;
}

void imprimirEncabezado(const string& columna1, const string& columna2,
                   const string& columna3, const string& columna4,
                   const string& columna5, const string& columna6) {
    int espaciosCentrales = 70, espaciosLaterales = (80 - espaciosCentrales) / 2;
    // Imprimir línea de separación
    cout << setw(espaciosLaterales) << setfill(' ') << " ";
    for (int i = espaciosLaterales; i < 77 - espaciosLaterales; ++i) {
        cout << '-';
    }
    cout << endl;

    // Imprimir espacios laterales
    for (int i = 0; i < espaciosLaterales; ++i) {
        cout << ' ';
    }

    // Imprimir el encabezado
    cout << left;
    cout << setw(12) << setfill(' ') << columna1;
    cout << setw(12) << columna2;
    cout << setw(12) << columna3;
    cout << setw(10) << columna4;
    cout << setw(10) << columna5;
    cout <<setw(8)<< columna6<< endl;

    // Imprimir línea de separación

    cout << setw(espaciosLaterales) << setfill(' ') << " ";
    for (int i = espaciosLaterales; i < 77 - espaciosLaterales; ++i) {
        cout << '-';
    }
    cout << endl;
}


void imprimirTabla(const string& columna1, const string& columna2, const string& columna3, int columna4, int columna5, int columna6) {
    int espaciosCentrales = 70, espaciosLaterales = (80 - espaciosCentrales) / 2;
    // Imprimir espacios laterales
    for (int i = 0; i < espaciosLaterales; ++i) {
        cout << ' ';
    }

    cout << setw(12) << setfill(' ') << columna1;
    cout << setw(12) << columna2;
    cout << setw(12) << columna3;
    cout << setw(10) << columna4;
    cout << setw(10) << columna5;
    cout <<setw(8)<< columna6<< endl;
}
 void enviarMensajeOperario(char* texto){

 cout<<texto;
 }




void escribirMensaje(char*& mensaje) {

    cout << "INGRESE EL MENSAJE: \n";
    const int maxSize = 100;

    // Reservar una cantidad inicial de memoria
    char* buffer = new char[maxSize];

    if (buffer == nullptr) {
        cerr << "Error al asignar memoria.";
        exit(1);
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.getline(buffer, maxSize);

    // Calcular la longitud real del texto ingresado
    int largo = strlen(buffer) + 1;

    // Ajustar la cantidad de memoria según la longitud real del texto
    delete[] mensaje;
    mensaje = new char[largo];
    strcpy(mensaje, buffer);

    // Liberar la memoria inicialmente reservada
    delete[] buffer;

}
void mostrarMensaje(const char* mensaje) {
    if(mensaje==nullptr){ cout<<"\n -NO HAY MENSAJE- ";}
        else{
        cout << "COMENTARIO RECIBIDO: \n \n" << mensaje << endl;
}
}

