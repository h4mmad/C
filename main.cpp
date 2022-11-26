#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
using namespace std::chrono;
using namespace std;

void bubble_sort(string *strings, int length_of_arr);
void print_strings(string *strings, int amount, int no_of_strings);

int main(){
    string data;
    int no_of_strings=5757;
    int i = 0;


    ifstream file("cpt316-assignment-2-strings.txt", ios::in);

    string strings[no_of_strings]; 

    
    while(getline(file, data)){
        strings[i] = data;
        i++;
    }

    auto start = high_resolution_clock::now();
    bubble_sort(strings, no_of_strings);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << duration.count() << endl;
    print_strings(strings, 10, no_of_strings);
    
    return 0;
}


void bubble_sort(string strings[], int length_of_arr){
    string temp;
    
    for (int i = 0; i < length_of_arr; i++)
    {
        for (int j = 1; j < length_of_arr-i; j++)
        {
            if (strings[j].compare(strings[j-1]) < 0)
            {
                temp = strings[j];
                strings[j] = strings[j-1];
                strings[j-1] = temp;
            }
        }
    }
}

void print_strings(string strings[], int amount, int no_of_strings){
    if (amount > no_of_strings){
        amount = no_of_strings;
    }
    for (int i = 0; i < amount; i++)
    {
        cout << strings[i] << endl;
    }
}
