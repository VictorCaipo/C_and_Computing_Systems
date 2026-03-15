#include <stdio.h>

struct flightType{
    char ID[4];//un caracter adicional para el caracter nulo
    int altitude;
    int longitude;
    int latitude;
    int heading;
    double airSpeed;
};

typedef struct flightType Flight;
//typedef struct nombre_struct simplificacion
Flight plane;


int main(void){

    //asignando valores
    plane.ID[0] = '0';
    plane.ID[1] = 'A';
    plane.ID[2] = 'B';
    plane.altitude = 5000;
    plane.longitude = 25;
    plane.latitude = 4000;
    plane.heading = 3;
    plane.airSpeed = 45;

    printf("ID: %c%c%c\n",plane.ID[0],plane.ID[1],plane.ID[2]);
    printf("Altitud: %d\n",plane.altitude);
    printf("Longitud: %d\n",plane.longitude);
    printf("Latitud: %d\n",plane.latitude);
    printf("Direccion: %d\n",plane.heading);
    printf("Velocidad: %f\n",plane.airSpeed);

    return 0;
}

/*
Ya conocemos los tipos de datos basicos. Sin embargo, en muchos pro
gramas es necesario representar objetos mas complejos, C permite
representar esto mediante estructuras (struct)

struct humano {
    double peso;
    double altura;
    int edad;
    //cada elemento dentro de la estructura se llama miembro
}

struct humano victor;
al crear victor, este ocupa un bloque continuo de memoria que con
tiene a todos sus miembros, en el run-time stack, los datos se
almacenan uno despues de otro

Para acceder a sus datos:
    victor.peso = 58.00;
    victor.altura = 1.69;
    victor.edad = 25;

typedef struct flighType Flight;
//Esto permite crear un nombre mas simple Flight plane, esto no cam
//bia la funcionalidad solo hace el codigo mas claro

*/