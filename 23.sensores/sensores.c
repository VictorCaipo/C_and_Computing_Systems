/*
Sistema embebido que monitorea sensores:
    No uses . dentro de funciones, solo ->
    Usa & para pasar argumentos
    Devuelve punteros correctamente
*/
#include <stdio.h>
#include <string.h>

const int total = 4;
struct sensor_features
{
    char id[6];
    double value;
    double threshold;
};

typedef struct sensor_features sensor_features;

void initSensor(sensor_features *s, char id[], double value, double threshold);
int isAlert(sensor_features *s);
void printSensor(sensor_features *s);
sensor_features* findCritical(sensor_features sensors[], int size);

int main(void){
    sensor_features sensors[total];//array de structuras
    
    initSensor(&sensors[0], "S1", 50.0, 40.0);
    initSensor(&sensors[1], "S2", 30.0, 35.0);
    initSensor(&sensors[2], "S3", 80.0, 60.0);
    initSensor(&sensors[3], "S4", 20.0, 25.0);

    for(int i = 0; i<total ; i++){
        printSensor(&sensors[i]);
    }

    sensor_features *critical = findCritical(sensors, total);

    if(critical != NULL){
        printf("Sensor mas critico: %s\n", critical->id);
    } else{
        printf("Ocurrio un error\n");
    }

    return 0;
}

void initSensor(sensor_features *s, char id_ini[], double value_ini, double threshold_ini){
    strcpy(s->id, id_ini);
    s->value = value_ini;
    s->threshold = threshold_ini;
}
int isAlert(sensor_features *s){
    if(s->value > s->threshold){
        return 1;//alerta
    } else{
        return 0;
    }
}
void printSensor(sensor_features *s){
    int estado = isAlert(s);//ojo
    if(estado){
        printf("Sensor: %s | Value: %f | Threshold: %f | ALERTA\n",
        s->id, s->value, s->threshold);
    } else{
        printf("Sensor: %s | Value: %f | Threshold: %f | OK\n",
        s->id, s->value, s->threshold);
    }
}
sensor_features* findCritical(sensor_features sensors[], int size){
    //devuelve el sensor mas critico
    sensor_features *best;
    double sensor_states[size];
    double max_error; 
    int n_sensor;
    for(int ii = 0; ii < size ; ii++){
        sensor_states[ii] = sensors[ii].value - sensors[ii].threshold;
    }
    //este array es inecesario talvez
    max_error = sensor_states[0];
    n_sensor = 0;
    for(int ii = 1; ii < size ; ii++){
        if(sensor_states[ii] > max_error){
            max_error = sensor_states[ii];
            n_sensor = ii;
        }
    }

    best = &sensors[n_sensor];
    //asignando direccion del puntero a la estructura sensor a punteor best
    return best;
}