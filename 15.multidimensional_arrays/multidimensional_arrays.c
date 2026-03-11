#include <stdio.h>

const int number_rows = 1080;
const int number_cols = 1920;

/*
We could add another braket nex to [col] and we will be able to work with
3D arrays
*/

int adjust(int image[number_rows][number_cols]){
    for (int row = 0; row < number_rows; row++ ){
        for (int col = 0; col < number_cols; col++ ){
            image[row][col] = image[row][col] / 2;
        }
    }
}

int main(void){
    /*
    The two dimensional array is saved in a way that we have rows at first
    , once the first row has finished it will print the second one.
    */
    return 0;
}