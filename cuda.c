#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFER_SIZE 4096
#define NO_OF_STRINGS 5757

int my_strcmp(const char*, const char *);
void odd_even_sort(char**);
void swap(char**, char**);

int main(){

    FILE* file = fopen("strings.txt", "r");
    char** strings = malloc(NO_OF_STRINGS * sizeof(char *));
    char buffer[BUFER_SIZE];

    
    int index = 0;
    while (fgets(buffer, BUFER_SIZE, file) != NULL)
    {
            strings[index] = malloc(strlen(buffer) * sizeof(char));
            strcpy(strings[index], buffer);
            index++;
    }

    odd_even_sort(strings);

    for(int i = 0; i<10; i++)
        printf("%s", strings[i]);
    

    fclose(file);
}

int my_strcmp(const char *X, const char *Y)
{
    while (*X)
    {
        if (*X != *Y) {
            break;
        }
 
        X++;
        Y++;
    }
 
    return *(const unsigned char*)X - *(const unsigned char*)Y;
}

void odd_even_sort(char **strings){
    char* temp;
    int is_sorted = 0;

    while (!is_sorted)
    {
        is_sorted = 1;

        for (int i = 0; i < NO_OF_STRINGS-2; i+=2)
        {
            if(my_strcmp(strings[i], strings[i+1]) > 0){
                swap(&strings[i], &strings[i+1]);
                is_sorted = 0;
            }  
        }

        
        for (int i = 1; i < NO_OF_STRINGS-2; i+=2)
        {
            if(my_strcmp(strings[i], strings[i+1]) > 0){
                swap(&strings[i], &strings[i+1]);
                is_sorted = 0;
            }  
        }
        
    }
}

void swap(char** str1, char** str2){
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp; 
}