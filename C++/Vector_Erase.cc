/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/31/2020 at 05:51 PM
 *
 * Vector_Erase.cc
 *
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void print_vector(vector<int> &list){
    for (const int &i : list)
	cout << i << " ";
    cout << endl;
}

int main(void){
    ifstream ifs{"Vector_Erase.txt"};
    
    int max_size;
    ifs >> max_size;
    vector<int> list(max_size);
    
    int temp;
    for (int &i : list){
	ifs >> temp; i = temp; 
    }
    
    // print_vector(list);
    int query1, query2;
    ifs >> query1 >> temp >> query2;
    
    list.erase(list.begin() + query1 - 1);
    cout << list.size() - ((query2 - temp)) << endl;

    list.erase(list.begin() + temp - 1, list.begin() + query2);
    print_vector(list);   
}
