#include <stdio.h>
#include <unistd.h>

int main(){

    putchar('a');
    sleep(5);
    putchar('b');
    putchar('\n');

    return 0;

    /*
    La salida tambien es afectada por el buffer, uno esperaria que se imprima
    el caracter a, espere 5 segundos y luego iprima b, pero esto no ocurre.
    En su lugar espera 5 segundos y luego imprime ab, esto debido a que al hacer
    putchar('a') este se guarda en el buffer, no se imprime, el valor envia su
    contenido al dispositivo de salida al hacer \n, luego recien se vacia el
    buffer y se envia su contenido al dispositivo de salida (flush)
    */
}