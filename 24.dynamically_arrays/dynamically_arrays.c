
#include <stdio.h>
#include <stdlib.h>//memoria dinamica

typedef struct{//datos de sensores
    char id[10];//10 bytes (es una direccion de memoria)(char *)
    double value;//8 bytes
} sensor_data;//sensor

int main(void){
    int n;//variable local vive en el stack

    printf("Cuantos sensores deseas registrar?: ");
    scanf("%d", &n);

    sensor_data *sensors = (sensor_data *) malloc(n*sizeof(sensor_data));
    /*
    malloc devuelve un puntero generico (void *, puntero que no 
    tiene tipo) al convertir este puntero generico en uno de tipo
    array de estructuras estos se definen uno por uno por medio del
    compilador: por ejemplo en 2 sensores:
    sensor 1 18 bytes y luego sensor 2 18 bytes, esto lo hacer automa
    ticamente el compilador, ya que el es el encargado de dar sentido
    a los punteros

    */

    if (sensors == NULL){
        printf("Error al asignar memoria\n");
        return 1;
    }

    for(int i=0; i<n; i++){
        printf("\nSensor %d\n", i+1);
        printf("ID: ");
        scanf("%s", sensors[i].id);//id ya es un puntero

        printf("Valor: ");
        scanf("%lf", &sensors[i].value);
    }
    printf("\n--- Lista de sensores ---\n");
    
    for(int i=0; i<n ; i++){
        printf("Sensor %d -> ID: %s | Valor: %.2f\n",
        i+1,
        sensors[i].id,
        sensors[i].value);
    }
    //liberando memoria
    free(sensors);
    //destruyendo los datos
    return 0;
}

/*
Los arrays tienen limitaciones, por lo que se introduce la memoria
dinamica como solucion mas flexible.

Problemas de usar arrays:
    Debes definir el size desde el inicio
    Si hay menos datos, desperdicias memoria
    Si hay mas datos el programa falla
    Insertar o eliminar elementos implica mover muchos datos

Solucion: memoria dinamica:
    Permite crear estructuras de datos que crecen o disminuyen segun
    necesidad, son mas eficientes para insertar/eliminar elementos

El programa usa 3 zonas principales de memoria en C:
    Stack
    Data global
    Heap
    *El heap crece hacia abajo, el stack crece hacia arriba, si se 
    encuentrar ocurre error (overflow)

En conclusion:
    El stack es automatico y temporal (controlado por el CPU y compilador)
    Heap es manuel y flexible, persistente (controlado por funciones)

Fisicamente el stack, data global y heap se encuentran en la misma 
memoria (RAM), la diferencia es como el sistema los organiza y gesti
ona
*/