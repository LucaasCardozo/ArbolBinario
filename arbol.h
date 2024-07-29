#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED


struct NodoE ;

typedef struct NodoE * Nodo;

typedef void * DatoPtr;


Nodo nuevoNodo(DatoPtr dato);

int comparacionInt(DatoPtr d1, DatoPtr d2);
int buscarInt(DatoPtr d1, DatoPtr d2);
int comparacionFloat(DatoPtr d1, DatoPtr d2);
int buscarFloat(DatoPtr d1, DatoPtr d2);

void insertar(Nodo nodo, DatoPtr dato, int(*resultadoComparacion)(DatoPtr, DatoPtr));

void mostrarNodoInt(Nodo nodo);
void mostrarNodoIntDatoPtr(void * dato);
void mostrarNodoFloat(Nodo nodo);
void mostrarNodoFloatDatoPtr(void * dato);
void mostrarNodoGenerico(Nodo nodo, void(*ptrFuncionMostrarNodo)(DatoPtr));

void preorden(Nodo nodo, void(*ptrFuncionMostrarNodo)(DatoPtr));

void inorden(Nodo nodo, void(*ptrFuncionMostrarNodo)(DatoPtr));

void postorden(Nodo nodo, void(*ptrFuncionMostrarNodo)(DatoPtr));

Nodo buscar(Nodo nodo, DatoPtr dato, int(*resultadoIgualacion)(DatoPtr, DatoPtr), int(*resultadoComparacion)(DatoPtr, DatoPtr));

void mostrarBuscado(Nodo nodo);

void liberarNodo(Nodo nodo);


#endif // ARBOL_H_INCLUDED
