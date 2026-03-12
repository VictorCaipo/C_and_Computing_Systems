#include <stdio.h>

int fibo_function(int n);

int main(void){

    int number;
    int result;

    printf("Fibonacci function\n");
    printf("Enter the number: ");
    scanf("%d", &number);

    result = fibo_function(number);
    printf("The answer is: %d \n",result);
    
    return 0;
}

int fibo_function(int n){
    if(n == 1 | n == 0){
        return 1;
    } else{
        return (fibo_function(n-1) + fibo_function(n-2));
    }
}