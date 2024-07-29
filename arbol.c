#include <stdio.h>
#include <stdlib.h>

#include "arbol.h"

struct NodoE {

    DatoPtr dato;

    Nodo izquierda;
    Nodo derecha;

};

Nodo nuevoNodo(DatoPtr dato){

    // Solicitar memoria
    Nodo nodo = (Nodo) malloc(sizeof(struct NodoE));

    // Asignar el dato e iniciar hojas
    nodo->dato = dato;
    nodo->izquierda =NULL;
    nodo->derecha = NULL;

    return nodo;

};

int comparacionInt(DatoPtr d1, DatoPtr d2){

    int num1 = *(int*)d1;
    int num2 = *(int*)d2;

    return num1 > num2;

};

int buscarInt(DatoPtr d1, DatoPtr d2){

    int num1 = *(int*)d1;
    int num2 = *(int*)d2;

    return num1 == num2;

};

int comparacionFloat(DatoPtr d1, DatoPtr d2){

    float num1 = *(float*)d1;
    float num2 = *(float*)d2;

    return num1 > num2;

};

int buscarFloat(DatoPtr d1, DatoPtr d2){

    float num1 = *(float*)d1;
    float num2 = *(float*)d2;

    return num1 == num2;

};

void insertar(Nodo nodo, DatoPtr dato, int(*resultadoComparacion)(DatoPtr, DatoPtr)){

    // ¿Izquierda o derecha?
    // Si es mayor va a la derecha
    if (resultadoComparacion(dato, nodo->dato)){

        // Tienes espacio a la derecha?
        if (nodo->derecha == NULL){

            nodo->derecha = nuevoNodo(dato);

        }else{

            // Si la derecha ya está ocupada, recursividad ;)
            insertar(nodo->derecha, dato, resultadoComparacion);

        }

    }else{

        if(resultadoComparacion(nodo->dato, dato)){

            // Si no, a la izquierda
            if (nodo->izquierda == NULL){

                nodo->izquierda = nuevoNodo(dato);

            }else{

                // Si la izquierda ya está ocupada, recursividad ;)
                insertar(nodo->izquierda, dato, resultadoComparacion);

            }
        }
    }
};

void mostrarNodoInt(Nodo nodo){

    printf("{ %d }", *(int*)(nodo->dato));

};

void mostrarNodoIntDatoPtr(void * dato){

    Nodo n = dato;

    mostrarNodoInt(n);

};

void mostrarNodoFloat(Nodo nodo){

    printf("{ %.2f }", *(float*)(nodo->dato));

};

void mostrarNodoFloatDatoPtr(void * dato){

    Nodo f = dato;

    mostrarNodoFloat(f);

};

void mostrarNodoGenerico(Nodo nodo, void(*ptrFuncionMostrarNodo)(DatoPtr)){

    ptrFuncionMostrarNodo(nodo);

};


void preorden(Nodo nodo, void(*ptrFuncionMostrarNodo)(DatoPtr)){

    if (nodo != NULL){

        mostrarNodoGenerico(nodo, ptrFuncionMostrarNodo);
        preorden(nodo->izquierda, ptrFuncionMostrarNodo);
        preorden(nodo->derecha, ptrFuncionMostrarNodo);

    }
};

void inorden(Nodo nodo, void(*ptrFuncionMostrarNodo)(DatoPtr)){

    if (nodo != NULL){

        inorden(nodo->izquierda, ptrFuncionMostrarNodo);
        mostrarNodoGenerico(nodo, ptrFuncionMostrarNodo);
        inorden(nodo->derecha, ptrFuncionMostrarNodo);

    }
};

void postorden(Nodo nodo, void(*ptrFuncionMostrarNodo)(DatoPtr)){

    if (nodo != NULL){

        postorden(nodo->izquierda, ptrFuncionMostrarNodo);
        postorden(nodo->derecha, ptrFuncionMostrarNodo);
        mostrarNodoGenerico(nodo, ptrFuncionMostrarNodo);

    }
};

Nodo buscar(Nodo nodo, DatoPtr dato, int(*resultadoIgualacion)(DatoPtr, DatoPtr), int(*resultadoComparacion)(DatoPtr, DatoPtr)){

    if (nodo == NULL){

        return NULL;

    }

    if (resultadoIgualacion(nodo->dato, dato)){

        return nodo;

    }

    if (resultadoComparacion(dato, nodo->dato)){

        printf("EL DATO BUSCADO NO ESTA AQUI --> DERECHA\n");
        return buscar(nodo->derecha, dato, resultadoIgualacion, resultadoComparacion);

    }
    else{

        printf("EL DATO BUSCADO NO ESTA AQUI --> IZQUIERDA\n");
        return buscar(nodo->izquierda, dato, resultadoIgualacion, resultadoComparacion);

    }
};

void mostrarBuscado(Nodo nodo){

    if(nodo == NULL){

        printf("No encontrado!!!!!\n");

    }else{

        printf("Encontrado\n");

    }

};

void liberarNodo(Nodo nodo){

        free(nodo);

};

