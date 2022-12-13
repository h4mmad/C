#include <stdio.h>
#include <stdlib.h>

int main(){
    char* string = "hello";
    char* strings[] = {"apple", "orang", "pinea"};

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            printf("%c", strings[i][j]);
        }
            printf("\n");
    }
}