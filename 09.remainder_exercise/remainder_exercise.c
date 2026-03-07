#include <stdio.h>

int  int_divide(int x, int y, int *quoptr, int *remptr);

int main(int argc, char *argv[]){

    int dividend;
    int divisor;
    int quotient;
    int remainder;
    int error;

    printf("Input dividend: ");
    scanf("%d", &dividend);
    /*
    scanf: espera leer un valor decimal y lo guardara en la direccion
    de la variable dividend, &dividend no es un puntero es una expresion
    que contiene una direccion (es decir un valor) el puntero puede
    almacenar varias direcciones
    */
    printf("Input divisor: ");
    scanf("%d", &divisor);

    error = int_divide(dividend, divisor, &quotient, &remainder);

    if(!error){
        printf("Answer: %d remainder %d\n", quotient, remainder);
    } else{
        printf("Int divide failed.\n");
    }
    return 0;
}

int int_divide(int x, int y, int *quoptr, int *remptr){

    if (y != 0){
        *quoptr = x/y;
        *remptr = x%y;
        return 0;//esto puede simplificarse pero es una convencion usar return 0 para indicar que todo salio bien
    } else{
        return -1;
    }
}


/*
Sometimes is convenient to have a pointer point to nothing, so we can
differentiate it from an actual pointer value. A pointer that points
to nothing is a null pointer

int *ptr;
ptr = NULL;
*/