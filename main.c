#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFER_SIZE 4096

void bubble_sort(char **strings, int no_of_strings){
    char* temp;
    for (int i = 0; i < no_of_strings; i++)
    {
        for (int j = 1; j < no_of_strings-i; j++)
        {
            int flag = strcmp(strings[j-1], strings[j]);
            if(flag > 0){
                temp = strings[j];
                strings[j] = strings[j-1];
                strings[j-1] = temp; 
            }  
        }
    }
}

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


    bubble_sort(strings, no_of_strings);    

    for (int i = 0; i < 10; i++)
    {
        printf("%s", strings[i]);
    }
    

    fclose(file);
    for (int i = 0; i < no_of_strings; i++)
        free(strings[i]);
    free(strings);
}