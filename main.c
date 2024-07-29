#include <stdio.h>
#include <stdlib.h>

#include "arbol.h"

int main()
{
    printf("\n --------------- Arbol Binario de enteros ---------------\n");

    int n1 = 28, n2 = 11, n3 = 96, n4 = 21, n5 = 6, n6 = 97, n7 = 1, n8 = 30, n9 = 10, n10 = 2;

    Nodo raiz = nuevoNodo(&n1);
    insertar(raiz, &n2, comparacionInt);
    insertar(raiz, &n3, comparacionInt);
    insertar(raiz, &n4, comparacionInt);
    insertar(raiz, &n5, comparacionInt);
    insertar(raiz, &n6, comparacionInt);
    insertar(raiz, &n7, comparacionInt);
    insertar(raiz, &n8, comparacionInt);
    insertar(raiz, &n9, comparacionInt);
    insertar(raiz, &n10,comparacionInt);

    printf("\nImprimiendo preorden\n");
    preorden(raiz, mostrarNodoIntDatoPtr);
    printf("\n\nImprimiendo inorden\n");
    inorden(raiz, mostrarNodoIntDatoPtr);
    printf("\n\nImprimiendo postorden\n");
    postorden(raiz, mostrarNodoIntDatoPtr);

    //Buscamos un numero entero
    int enteroABuscar = 30;

    printf("\n\nBuscando el %d\n", enteroABuscar);
    Nodo buscado = buscar(raiz, &enteroABuscar, buscarInt, comparacionInt);

    mostrarBuscado(buscado);

    //Liberamos el buscado
    liberarNodo(buscado);

    //Buscamos otro numero entero
    enteroABuscar = 10;

    printf("\n\nBuscando el %d\n", enteroABuscar);
    buscado = buscar(raiz, &enteroABuscar, buscarInt, comparacionInt);

    mostrarBuscado(buscado);

    //Liberamos el buscado
    liberarNodo(buscado);

    //Buscamos otro numero entero
    enteroABuscar = 96;

    printf("\n\nBuscando el %d\n", enteroABuscar);
    buscado = buscar(raiz, &enteroABuscar, buscarInt, comparacionInt);

    mostrarBuscado(buscado);

    //Liberamos la raiz y el buscado
    liberarNodo(raiz);
    liberarNodo(buscado);

    printf("\n\n --------------- Arbol Binario de flotantes ---------------\n");

    float f1 = 15.23, f2 = 1, f3 = 9.54, f4 = 74.20, f5 = 5.23, f6 = 54.28, f7 = 33.56, f8 = 86.19, f9 = 25.17, f10 = 20.98;

    raiz = nuevoNodo(&f1);
    insertar(raiz, &f2, comparacionFloat);
    insertar(raiz, &f3, comparacionFloat);
    insertar(raiz, &f4, comparacionFloat);
    insertar(raiz, &f5, comparacionFloat);
    insertar(raiz, &f6, comparacionFloat);
    insertar(raiz, &f7, comparacionFloat);
    insertar(raiz, &f8, comparacionFloat);
    insertar(raiz, &f9, comparacionFloat);
    insertar(raiz, &f10,comparacionFloat);

    printf("\nImprimiendo preorden\n");
    preorden(raiz, mostrarNodoFloatDatoPtr);
    printf("\n\nImprimiendo inorden\n");
    inorden(raiz, mostrarNodoFloatDatoPtr);
    printf("\n\nImprimiendo postorden\n");
    postorden(raiz, mostrarNodoFloatDatoPtr);

    //Buscamos un numero flotante
    float flotanteABuscar = 17.25;

    printf("\n\nBuscando el %.2f\n", flotanteABuscar);
    buscado = buscar(raiz, &flotanteABuscar, buscarFloat, comparacionFloat);

    mostrarBuscado(buscado);

    //Liberamos el buscado
    liberarNodo(buscado);

    //Buscamos otro numero flotante
    flotanteABuscar = 5.23;

    printf("\n\nBuscando el %.2f\n", flotanteABuscar);
    buscado = buscar(raiz, &flotanteABuscar, buscarFloat, comparacionFloat);

    mostrarBuscado(buscado);

    //Liberamos el buscado
    liberarNodo(buscado);

    //Buscamos otro numero flotante
    flotanteABuscar = 54.18;

    printf("\n\nBuscando el %.2f\n", flotanteABuscar);
    buscado = buscar(raiz, &flotanteABuscar, buscarFloat, comparacionFloat);

    mostrarBuscado(buscado);

    //Liberamos la raiz y el buscado
    liberarNodo(raiz);
    liberarNodo(buscado);

    return 0;
}
