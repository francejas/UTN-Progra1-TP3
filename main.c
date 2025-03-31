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
int contieneCaracter(char array[], int v, char dato);

int main(int argc, char *argv[]) {
    int selected;

    Pila pila0;

    inicpila(&pila0);


    int array0[DIMENSION];
    float array1[DIMENSION];
    char array2[DIMENSION];
    char array03[DIMENSION] = {'a', 'c', 'e', 'g'};

    int v = 0;

    char datoChar;


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
            case 6:
                v = cargaArrayChar(array2,v,DIMENSION);
                //sacar dato por datoChar y preguntar qe es lo mas correcto
                char dato;
                muestraArregloChar(array2, v);
                printf("Ingrese un caracter a buscar: ");
                scanf(" %c",&dato);
                if (contieneCaracter(array2,v,dato)){
                        printf("El dato %c se encuentra en el arreglo \n",dato);
                }else{
                    printf("El dato %c NO se encuentra en el arreglo \n",dato);
                }
                system("PAUSE");
                break;
            case 7:
                muestraArregloChar(array03,4);
                printf("Ingrese un caracter a insertar en el arreglo \n");
                scanf(" %c",&datoChar);
                insertarOrdenadoChar(array03,&v,datoChar);
                printf("Arreglo con el caracter insertado: \n");
                muestraArregloChar(array03,v);
                system("PAUSE");
                break;
            case 0:
                printf("\n\nTERMINATE THE PROGRAM\n");
                break;
            default:
                printf("\nOpción no válida. Intente nuevamente.\n");
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
    printf("\n1- Hacer una función que reciba como parámetro un arreglo de números enteros y permita que el usuario ingrese valores al mismo por teclado.");
    printf("\n2- Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y los muestre por pantalla.");
    printf("\n3- Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y calcule la suma de sus elementos.");
    printf("\n4- Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos) cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila.");
    printf("\n5- Realizar una función que sume los elementos de un arreglo de números reales (float) de dimensión 100. (se recomienda hacer una función para cargar y otra para mostrar para este tipo de dato asociado al arreglo).");
    printf("\n6- Realizar una función que indique si un elemento dado se encuentra en un arreglo de caracteres.");
    printf("\n7- Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente, conservando el orden.");
    printf("\n0- SALIR");
    printf("\n\nIngrese su elección: ");
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

int cargaArrayChar(char array[], int v, int max_dim){
    char respuesta;

    do {
        printf("Ingrese un valor al arreglo, en la posicion a[%d]: ", v);
        fflush(stdin);
        scanf("%c", &array[v]);
        v++;
        printf("\nDesea ingresar otro numero? (s/n): ");
        fflush(stdin);
        scanf(" %c", &respuesta);

    }while((respuesta=='s' || respuesta=='S') && v<max_dim);

    return v;
}

void muestraArregloChar (char array[], int v){
    printf("Su arreglo: \n");

    for (int i=0;i<v;i++){
        printf("%c | ", array[i]);
    }
    printf("\n");
}

int contieneCaracter(char array[], int v, char dato){
    for (int i=0;i<v;i++){
        if (array[i]== dato){
            return 1;
        }
    }

    return 0;
}

void insertarOrdenadoChar(char array[], int *v, char dato){
   //encontrar la posicion adecuada
   int i=0;
   while(i<*v && array[i]<dato){
    i++;
   }
    //Mover los elementos a la derecha

    for(int j=*v;j>1;j--){
        array[j]=array[j-1];
    }
    array[i]=dato;
    (*v)++;
}
