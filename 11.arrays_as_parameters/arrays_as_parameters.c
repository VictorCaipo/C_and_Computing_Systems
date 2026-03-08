#include <stdio.h>

const int max_num = 5;

int average(int input_values[]);

int main(void){
    int mean;
    int numbers[max_num];

    printf("Enter %d numbers.\n", max_num);

    for(int index = 0; index<max_num; index++ ){
        printf("Input number %d: ",index);
        scanf("%d", &numbers[index]);
        //Podemos usar &number, pero solo para casos simples, tiene limites, por eso los punteros son necesarios
    }

    mean = average(numbers);

    printf("The average of these numbers is: %d\n",mean);

}

int average(int inputvalues[]){//inputvalues es el primer valor del stack frame de average y este apunta al primer termino de numbers (number[0])
    int sum = 0;

    for(int index = 0; index<max_num; index++){
        sum = sum + inputvalues[index];
    }
    return (sum/max_num);
}