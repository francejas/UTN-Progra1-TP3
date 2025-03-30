#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

#define DIMENSION 100



// Prototipos de funciones
int menu();
int cargaArray(int array[], int v, int max_dim);
void muestraArreglo(int array[], int v);
int sumaElementosArray(int array[], int v);
void pasarArrayAPila(Pila *pila, int array[], int v);
int cargaArrayFloat(float array[], int v, int max_dim);
void muestraArregloFloat(float array[], int v);
float sumaElementosArrayFloat(float array[], int v);

int main(int argc, char *argv[]) {
    int selected;

    Pila pila0;

    inicpila(&pila0);


    int array0[DIMENSION];
    float array1[DIMENSION];
    int v = 0;


    do {
        selected = menu();
        switch (selected) {
            case 1:
                v = cargaArray(array0, v, DIMENSION);
                printf("\n");
                muestraArreglo(array0, v);
                system("PAUSE");
                break;
            case 2:
                v = cargaArray(array0, v, DIMENSION);
                printf("\n");
                muestraArreglo(array0, v);
                system("PAUSE");
                break;
            case 3:
                v = cargaArray(array0, v, DIMENSION);
                printf("\n");
                muestraArreglo(array0, v);
                int suma=sumaElementosArray(array0,v);
                printf("Suma de los elementos del array: %d \n",suma);
                system("PAUSE");
                break;
            case 4:
                v = cargaArray(array0, v, DIMENSION);
                printf("\n");
                muestraArreglo(array0, v);
                pasarArrayAPila(&pila0,array0,v);
                printf("Pila: \n");
                mostrar(&pila0);
                system("PAUSE");
                break;
            case 5:
                v=cargaArrayFloat(array1,v,DIMENSION);
                printf("\n");
                muestraArregloFloat(array1, v);

                //porqe aca si pongo suma no anda ??

                float sumaFloat=sumaElementosArrayFloat(array1,v);
                printf("Suma de los elementos del array: %.2f \n",sumaFloat);

                system("PAUSE");
                break;
            case 0:
                printf("\n\nTERMINATE THE PROGRAM\n");
                break;
            default:
                printf("\nOpci�n no v�lida. Intente nuevamente.\n");
                system("PAUSE");
                break;
        }
    } while (selected != 0);
    return 0;
}

int menu() {
    system("color 1F");
    int input;
    system("cls");
    printf("\nLABORATORIO 1");
    printf("\n----------");
    printf("\nLIST MENU");
    printf("\n-----------");
    printf("\n1- Hacer una funci�n que reciba como par�metro un arreglo de n�meros enteros y permita que el usuario ingrese valores al mismo por teclado.");
    printf("\n2- Hacer una funci�n que reciba como par�metro un arreglo y la cantidad de elementos (v�lidos) cargados en �l y los muestre por pantalla.");
    printf("\n3- Hacer una funci�n que reciba como par�metro un arreglo y la cantidad de elementos (v�lidos) cargados en �l y calcule la suma de sus elementos.");
    printf("\n4- Hacer una funci�n que reciba como par�metro un arreglo, la cantidad de elementos (v�lidos) cargados en �l y una Pila. La funci�n debe copiar los elementos del arreglo en la pila.");
    printf("\n5- Realizar una funci�n que sume los elementos de un arreglo de n�meros reales (float) de dimensi�n 100. (se recomienda hacer una funci�n para cargar y otra para mostrar para este tipo de dato asociado al arreglo).");
    printf("\n6- Realizar una funci�n que indique si un elemento dado se encuentra en un arreglo de caracteres.");
    printf("\n0- SALIR");
    printf("\n\nIngrese su elecci�n: ");
    scanf("%d", &input);
    return input;
}

int cargaArray(int array[], int v, int max_dim) {
    char respuesta;
    do {

        printf("Ingrese un valor al arreglo, en la posicion a[%d]: ", v);
        scanf("%d", &array[v]);
        v++;
        printf("\nDesea ingresar otro numero? (s/n): ");
        fflush(stdin);
        scanf(" %c", &respuesta);
    } while ((respuesta == 's' || respuesta == 'S') && v < max_dim);

    return v;
}

void muestraArreglo(int array[], int v) {

    printf("Su arreglo:\n");

    for (int i = 0; i < v; i++) {
        printf("%d | ", array[i]);
    }
    printf("\n");
}

int sumaElementosArray (int array[], int v){
    int suma=0;
    for (int i=0;i<v;i++){
        suma=suma+array[i];
    }

    return suma;
}

void pasarArrayAPila (Pila *pila, int array[], int v){

    for (int i=0;i<v;i++){
        apilar(pila, array[i]);
    }

}

int cargaArrayFloat(float array[], int v, int max_dim) {
    char respuesta;
    do {
        printf("Ingrese un valor al arreglo, en la posicion a[%d]: ", v);
        fflush(stdin);
        scanf("%f", &array[v]);
        v++;
        printf("\nDesea ingresar otro numero? (s/n): ");
        fflush(stdin);
        scanf(" %c", &respuesta);
    } while ((respuesta == 's' || respuesta == 'S') && v < max_dim);

    return v;
}

void muestraArregloFloat(float array[], int v){
    printf("Su arreglo:\n");

    for(int i=0;i<v;i++){
        printf("%.2f | ", array[i]);
    }
    printf("\n");
}

float sumaElementosArrayFloat(float array[], int v){
    float suma=0;

    for(int i=0;i<v;i++){
        suma=suma+array[i];
    }
    return suma;
}
