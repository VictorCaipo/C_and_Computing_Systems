#include <stdio.h>

const int max_string = 20;

int string_leng(char string[]);

/*
Null caracter: 
    whose ASCII value is 0; it serves as a sentinel that
    identifies the end of a string
Important:
    single characters ' '
    strings " "
*/
int main(void){

    char word[8];
    word[0]= 'v';
    word[1]= 'a';
    word[2]= 'l';
    word[3]= 'e';
    word[4]= '\0';
    word[5]= 'r';

    printf("How the null caracter works:\n");
    printf("%s\n",word);

    char input[max_string];
    int lenght = 0;
    printf("Input a word less than 20 characters:");
    scanf("%s",input);
    lenght = string_leng(input);
    printf("The word contains %d characters\n",lenght);
    return 0;
}

int string_leng(char string[]){
    int index = 0;

    while (string[index] != '\0'){
        index = index + 1;
    }
    return index;
}