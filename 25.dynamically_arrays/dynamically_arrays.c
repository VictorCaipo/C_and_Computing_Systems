#include <stdio.h>
#include <stdlib.h>

int main(void){

    int n;
    printf("Cuantos numeros quieres guardar? ");
    scanf("%d", &n);

    //Reservamos memoria
    int *arr = (int *) malloc(sizeof(int) *n);//puntero int

    if(arr == NULL){
        printf("Error al asignar memoria\n");
        return 1;
    }

    //Leer datos
    for(int i=0; i<n ; i++){
        printf("Numero %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    //Mostrar datos
    printf("\nNumeros ingresados:\n");
    for(int i=0; i<n ; i++){
        printf("%d\n", *(arr + i));
    }

    //Leer memoria
    free(arr);

    return 0;
}

/*
Arrays de tamano dinamico:
    En C se puede crear arreglos de tamano dinamico usando malloc (me
    moria en el heap)
    Se reserva memoria en bytes, devuelve un puntero void *, si falla
    devuelve NULL.
    La funcion sizeof es clave, permite que el codigo sea portable y
    funcione en diferentes sistemas
    Para liberar memoria usamos free()
    Calloc y realloc son otras funciones utilies

*/