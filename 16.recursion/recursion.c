#include <stdio.h>

/*
Recursion is a tool useful in some cases, because they are easier to
implement, but it has a cost, so be carefull.
*/
int running_sum(int n);

int main(void){

    printf("What recursion is?\n");
    int number = 4;
    printf("The sum of 1 to 4 is: %d\n",running_sum(4));
    return 0;
}

int running_sum(int n){
    if(n == 1){
        return 1;
    } else{
        return (n + running_sum(n-1));
    }
}