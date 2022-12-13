#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <omp.h>
using namespace std::chrono;
using namespace std;

void odd_even_sort(string*, int);
void my_odd_even_sort(string* ,int);
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

    cout << "time taken for odd even sort using OpenMP is " << duration.count() << " milliseconds"<< endl;
    print_strings(strings, 10, no_of_strings);
    
    free(strings);
}


void odd_even_sort(string *a, int n){
    string temp;
    int phase, i;
  for(phase=0;phase<n;++phase)
  {
    if(phase%2==0) //even phase
    {
#pragma omp parallel for  default(none) shared(a,n) private(i,temp)
      for(i=1;i<n;i+=2)
	if(a[i-1] > a[i])
	{
	  temp = a[i];
	  a[i] = a[i-1];
	  a[i-1] = temp;
	}
    }
    else //odd phase
    {
#pragma omp parallel for default(none) shared(a,n) private(i,temp)
      for(i=1;i<n-1;i+=2)
	if(a[i] > a[i+1])
	{
      	  temp = a[i];
	  a[i] = a[i+1];
	  a[i+1] = temp;
	}
    }
  }
    
}

void my_odd_even_sort(string* strings, int no_of_strings){
    char* temp;
    bool is_sorted = false;

    while (!is_sorted)
    {
        is_sorted = true;

        
        // It compares the even indexed element with the next and swaps
        // if the i'th string is larger than i+1, they swap
        // that's why int i is intialised to 0
        // i gets incremented by 2 values, therefore 0 wil become 2, 2 will become 4 and so on...
        #pragma omp parallel for private(is_sorted)
        for (int i = 0; i < no_of_strings-2; i+=2)
        {
            if(strings[i].compare(strings[i+1]) > 0){
                swap(strings[i], strings[i+1]);
                is_sorted = false;
                // cout << "In first loop " << omp_get_thread_num() << endl;
            }  
        }

        // It compares the odd indexed element with the next and swaps
        // if the i'th string is larger than i+1, they swap
        // that's why int i is intialised to 1
        // i gets incremented by 2 values, therefore 1 wil become 3, 3 will become 5 and so on...
        #pragma omp parallel for private(is_sorted)
        for (int i = 1; i < no_of_strings-2; i+=2)
        {
            if(strings[i].compare(strings[i+1]) > 0){
                swap(strings[i], strings[i+1]);
                is_sorted = false;
                // cout << "In second loop " <<omp_get_thread_num() << endl;

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


