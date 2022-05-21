#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const int maxC=3;
const int maxCstr=20;

void ejercicio1();
void ejercicio2();
void ejercicio3();
void ejercicio4();
void ejercicio5();
void ejercicio6();
void ejercicio7();
void ejercicio8();
void ejercicio9();
void ejercicio10();
void ejercicio11();

void cargarMatriz(int mat[][maxC], int filas);
void mostrarMatriz(int mat[][maxC], int filas);
void cargarRand(int mat[][maxC], int filas);
int sumarMatriz(int mat[][maxC], int filas);
float promedioMatriz(int mat[][maxC], int filas, int suma);
int busquedaElem(int mat[][maxC], int filas, int dato);
int cargarStr(char mat[][maxCstr], int filas);
void mostrarStr(char mat[][maxCstr], int cantidad);
int busquedaStr(char mat[][maxCstr], int filas, int cantidad, char palabra[]);
int menorElem(char mat[][maxCstr], int filas, int i, int cantidad);
void xSeleccion(char mat[][maxCstr], int filas, int cantidad);

int main(){
    int seleccion=0;
    char seguir='s';

    do{
        puts("\t----SELECCIONE UN EJERCICIO----\n");
        printf("\nEJERCICIO 1");
        printf("\nEJERCICIO 2");
        printf("\nEJERCICIO 3");
        printf("\nEJERCICIO 4");
        printf("\nEJERCICIO 5");
        printf("\nEJERCICIO 6");
        printf("\nEJERCICIO 7");
        printf("\nEJERCICIO 8");
        printf("\nEJERCICIO 9");
        printf("\nEJERCICIO 10");
        printf("\nEJERCICIO 11\n\n");
        scanf("%i", &seleccion);


        switch(seleccion){
        case 1:
            {
                system("cls");
                ejercicio1();
                break;
            }
        case 2:
            {
                system("cls");
                ejercicio2();
                break;
            }
        case 3:
            {
                system("cls");
                ejercicio3();
                break;
            }
        case 4:
            {
                system("cls");
                ejercicio4();
                break;
            }
        case 5:
            {
                system("cls");
                ejercicio5();
                break;
            }
        case 6:
            {
                system("cls");
                ejercicio6();
                break;
            }
        case 7:
            {
                system("cls");
                ejercicio7();
                break;
            }
        case 8:
            {
                system("cls");
                ejercicio8();
                break;
            }
        case 9:
            {
                system("cls");
                ejercicio9();
                break;
            }
        case 10:
            {
                system("cls");
                ejercicio10();
                break;
            }
        case 11:
            {
                system("cls");
                ejercicio11();
                break;
            }
        }

        system("pause");
        system("cls");

        printf("Desea ver otro ejercicio? s/n\n");
        fflush(stdin);
        scanf("%c", &seguir);

    }while(seguir=='s');


    return 0;
}

void cargarMatriz(int mat[][maxC], int filas){
    puts("\nIngrese los numeros para la matriz\n");

    for(int i=0; i<filas; i++){
        for(int a=0; a<maxC; a++){
            scanf("%i", &mat[i][a]);
        }
    }
}

void cargarRand(int mat[][maxC], int filas){

    srand(time(NULL));

    for(int i=0; i<filas; i++){
        for(int a=0; a<maxC; a++){
            mat[i][a]=rand()%9+1;
        }
    }
}

int cargarStr(char mat[][maxCstr], int filas){
    int a=0;
    char continuar='s';

    puts("\nIngrese palabras de hasta 10 caracteres");

    for(a=0; (a<filas) && (continuar=='s'); a++){
        puts("\n");
        fflush(stdin);
        gets(mat[a]);
        printf("\nDesea ingresar otra palabra? s/n Respuesta: \n\n");
        fflush(stdin);
        scanf("%c",&continuar);
    }

    return a;
}

void mostrarStr(char mat[][maxCstr], int cantidad){
    int i=0, a=0;

    for(i=0; i<cantidad; i++){
        printf("| %s |", mat[i]);
        puts("\n");
    }
}

void mostrarMatriz(int mat[][maxC], int filas){

    for(int i=0; i<filas; i++){
        for(int a=0; a<maxC; a++){
            printf("| %d |", mat[i][a]);
        }
        puts("\n");
    }
}

int sumarMatriz(int mat[][maxC], int filas){
    int sumaT=0;

    for(int i=0; i<filas; i++){
        for(int a=0; a<maxC; a++){
            sumaT=sumaT+mat[i][a];
        }
    }

    return sumaT;
}

float promedioMatriz(int mat[][maxC], int filas, int suma){
    float cantidad=maxC*filas;

    float promedio=suma/cantidad;

    return promedio;
}

int busquedaElem(int mat[][maxC], int filas, int dato){
    int flag=0, i=0, a=0;

    while(flag==0 && i<filas && a<maxC){
        for(i=0; i<filas && flag==0; i++){
            for(a=0; a<maxC && flag==0; a++){
                if(mat[i][a]==dato){
                    flag=1;
                }
            }
        }
    }

    return flag;
}

int busquedaStr(char mat[][maxCstr], int filas, int cantidad, char palabra[]){
    int a=0, flag=0, comparador=0;

    while(flag==0 && a<cantidad){
        comparador=strcmpi(palabra, mat[a]);

        if(comparador==0){
            flag=1;
        }else{
            a++;
        }
    }

    if(flag==0)
        a=-1;

    return a;
}

int menorElem(char mat[][maxCstr], int filas, int a, int cantidad){
    int posicion=a;
    int i=a+1;
    char menor[20];

    strcpy(menor, mat[a]);

    while(i<cantidad){

        if(strcmp(menor, mat[i])==1){
            strcpy(menor, mat[i]);
            posicion=i;
        }
        i++;
    }

    return posicion;
}

void xSeleccion(char mat[][maxCstr], int filas, int cantidad){
    int i=0, posicion=0;
    char aux[20];

    while(i<cantidad-1){
        posicion=menorElem(mat, filas, i, cantidad);

        strcpy(aux, mat[posicion]);
        strcpy(mat[posicion], mat[i]);
        strcpy(mat[i], aux);
        i++;
    }
}

void ejercicio1(){
    int mat1[3][maxC];

    cargarMatriz(mat1, 3);
    mostrarMatriz(mat1, 3);
}

void ejercicio2(){
    int mat2[3][maxC];

    cargarMatriz(mat2, 3);
    mostrarMatriz(mat2, 3);
}

void ejercicio3(){
    int mat3[3][maxC];

    cargarRand(mat3, 3);
    mostrarMatriz(mat3, 3);
}

void ejercicio4(){
    int mat4[3][maxC];

    cargarRand(mat4, 3);
    mostrarMatriz(mat4, 3);

    int suma=sumarMatriz(mat4, 3);
    printf("\nLa suma de la matriz es: %d\n", suma);
}

void ejercicio5(){
    int mat5[3][maxC];

    cargarRand(mat5, 3);
    mostrarMatriz(mat5, 3);

    int suma=sumarMatriz(mat5, 3);
    float promedio=promedioMatriz(mat5, 3, suma);
    printf("\nEl promedio de la matriz es: %.2f\n", promedio);
}

void ejercicio6(){
    int mat6[3][maxC];

    cargarRand(mat6, 3);
    mostrarMatriz(mat6, 3);

    int dato=0;
    puts("\nIngrese el numero para saber si esta en la matriz:\n");
    scanf("%d", &dato);

    int flag=busquedaElem(mat6, 3, dato);

    if(flag==0)
        puts("\nEl numero no se encuentra\n");
    else
        puts("\nEl numero fue enScontrado\n");
}

void ejercicio7(){
    int mat7[25][maxCstr];

    int cantidad=cargarStr(mat7, 25);
    mostrarStr(mat7, cantidad);
    printf("\nLa cantidad de palabras cargadas es: %d", cantidad);
}

void ejercicio8(){
    int mat8[25][maxC];

    int cantidad=cargarStr(mat8, 25);
    mostrarStr(mat8, cantidad);
}

void ejercicio9(){
    char mat9[25][maxC];
    char palabra[1];

    int cantidad=cargarStr(mat9, 25);

    puts("\nIngrese la palabra que busca: \n");
    fflush(stdin);
    gets(palabra);

    int posicion=busquedaStr(mat9, 25, cantidad, palabra);

    if(posicion==-1){
        puts("\nNo se encontro la palabra\n");
    }else{
        printf("\nLa palabra esta en la posicion: %d\n", posicion);
    }
}

void ejercicio10(){
    char mat10[20][maxCstr];
    char palabra[20];

    int cantidad=cargarStr(mat10, 20);

    xSeleccion(mat10, 20, cantidad);

    puts("\nIngrese la palabra que busca: \n");
    fflush(stdin);
    gets(palabra);

    int posicion=busquedaStr(mat10, 25, cantidad, palabra);

    if(posicion==-1){
        puts("\nNo se encontro la palabra\n");
    }else{
        printf("\nLa palabra esta en la posicion: %d\n", posicion);
    }
}

void ejercicio11(){
    char mat11[20][maxCstr];

    int cantidad=cargarStr(mat11, 20);

    xSeleccion(mat11, 20, cantidad);
    mostrarStr(mat11, cantidad);
}

///Terminado;




