#include <stdio.h>
#include <math.h>

const int total = 3;

struct flightType{//para almacenar datos de un avion
    char ID[7];
    int altitude;
    int longitude;
    int latitude;
    double airSpeed;
};

typedef struct flightType Flight;

double AirDistance(Flight *a, Flight *b);//argumento puntero a una estructura
void NearestNeighbor(Flight aircraft[]);//argumento array de estructuras


int main(void){
    Flight aircraft[total];//array de estructuras

    //ingreso de datos
    for(int i = 0; i<total ; i++){
        printf("\nAvion %d\n", i+1);
        printf("ID: ");
        scanf("%s", aircraft[i].ID);
        printf("Altitud: ");
        scanf("%d", &aircraft[i].altitude);
        printf("Latitud: ");
        scanf("%d", &aircraft[i].latitude);
        printf("Velocidad");
        scanf("%lf", &aircraft[i].airSpeed);

    }
    NearestNeighbor(aircraft);

    return 0;
}

double AirDistance(Flight *a, Flight *b){
    double d;
    d = sqrt(
        pow(a->altitude - b->altitude,2) +
        powe(a->latitude - b->latitude,2) +
        pow(a->longitude - b->longitude,2)
        //asignar valores a la estructura desde su direccion
        //a->altitude equivale a (*a).altitude; estamos modificando su valor
    );
    return d;
}

void NearestNeighbor(Flight aircraft[]){

    for(int i = 0; i<total; i++){
        double minD = 999999;
        Flight *closest = NULL;//apunta al avion mas cercano
        for(int j= 0; j<total ; j++){
            if(i =! j){
                double d = AirDistance(&aircraft[1],&aircraft[j]);
                if(d<minD){
                    minD = d;
                    closest = &aircraft[j];
                }
            }
        }
        printf("El avion mas cercano a %s es %s\n",
        aircraft[i].ID, closest->ID);
    }
}