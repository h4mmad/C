#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
using namespace std::chrono;
using namespace std;

void odd_even_sort(string *strings, int length_of_arr);
void print_strings(string *strings, int amount, int no_of_strings);

int main(){
    string data;
    int no_of_strings=0;
    int i = 0;


    ifstream file("cpt316-assignment-2-strings.txt");

    while (getline(file, data))
        no_of_strings++;

    file.clear();
    file.seekg(0);
    string *strings = new string[no_of_strings];

    
    while(getline(file, data)){
        strings[i] = data;
        i++;
    }

    auto start = high_resolution_clock::now();
    odd_even_sort(strings, no_of_strings);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << duration.count() << endl;
    print_strings(strings, 10, no_of_strings);
    
    free(strings);
}


void odd_even_sort(string *strings, int length_of_arr){
    string temp;

    bool is_sorted = false;

    while (!is_sorted)
    {
        is_sorted = true;

        for (int i = 0; i < length_of_arr-2; i+=2)
        {
            if (strings[i+1].compare(strings[i]) < 0)
            {
                temp = strings[i];
                strings[i] = strings[i+1];
                strings[i+1] = temp;
                is_sorted = false;
            }
        }
        for (int i = 1; i < length_of_arr-2; i+=2)
        {
            if (strings[i+1].compare(strings[i]) < 0)
            {
                temp = strings[i];
                strings[i] = strings[i+1];
                strings[i+1] = temp;
                is_sorted = false;
            }
        }
    }
    
}

void print_strings(string *strings, int amount, int no_of_strings){
    if (amount > no_of_strings){
        amount = no_of_strings;
    }
    for (int i = 0; i < amount; i++)
    {
        cout << strings[i] << endl;
    }
}
