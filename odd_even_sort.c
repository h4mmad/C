#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define BUFER_SIZE 4096

//author - Mohammed Hammad 154434

void odd_even_sort(char **strings, int no_of_strings);
void swap(char** str1, char** str2);

int main(){
    FILE* file = fopen("cpt316-assignment-2-strings.txt", "r");
    char **strings; // we need an array of pointers to char arrays i.e strings
    int no_of_strings = 0;

    if(file == NULL){
        printf("The file cannot be opened. \n");
    }
    else{

        char buffer[BUFER_SIZE]; // this stores each string temporarily when read
        
        
         //this variable will store the number of 
        while (fgets(buffer, BUFER_SIZE, file) != NULL) //this loop goes throught the text file and stores the number of strings
        {
            if (buffer != NULL) // if the read buffer is not null increment the no_of_strings value;
            {
                no_of_strings++;
            }
        }

        strings = malloc(no_of_strings * sizeof(char *)); // allocate memory, to hold pointers to the number of strings


        int i = 0;
        rewind(file); //we go back to the start of the file;

        //we read again and store each string in an array
        while (fgets(buffer, BUFER_SIZE, file) != NULL)
        {
            // printf("%d", strlen(buffer));
            strings[i] = malloc(strlen(buffer)-1 * sizeof(char)); // each char array will be allocated the amount of space that is required, we subtract one as \n is counted
            strcpy(strings[i], buffer); //copy the char array from the buffer to the strings array
            i++;
        }
    }

    clock_t t = clock();

    odd_even_sort(strings, no_of_strings);   

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("odd even sort took %f milliseconds to execute in C wihtout parallelism \n", time_taken*1000);

    for (int i = 0; i < 10; i++)
    {
        printf("%s", strings[i]);
    }
    

    fclose(file);
    for (int i = 0; i < no_of_strings; i++)
        free(strings[i]);
    free(strings);
}

void odd_even_sort(char **strings, int no_of_strings){
    char* temp;
    bool is_sorted = false;

    while (!is_sorted)
    {
        is_sorted = true;

        
        // It compares the even indexed element with the next and swaps
        // if the i'th string is larger than i+1, they swap
        // that's why int i is intialised to 0
        // i gets incremented by 2 values, therefore 0 wil become 2, 2 will become 4 and so on...
        for (int i = 0; i < no_of_strings-2; i+=2)
        {
            if(strcmp(strings[i], strings[i+1]) > 0){
                swap(&strings[i], &strings[i+1]);
                is_sorted = false;
            }  
        }

        // It compares the odd indexed element with the next and swaps
        // if the i'th string is larger than i+1, they swap
        // that's why int i is intialised to 1
        // i gets incremented by 2 values, therefore 1 wil become 3, 3 will become 5 and so on...
        for (int i = 1; i < no_of_strings-2; i+=2)
        {
            if(strcmp(strings[i], strings[i+1]) > 0){
                swap(&strings[i], &strings[i+1]);
                is_sorted = false;
            }  
        }
        
    }
}

void swap(char** str1, char** str2){
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp; 
}