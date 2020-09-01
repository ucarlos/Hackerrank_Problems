#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, queries;
    cin >> n >> queries;
    vector<vector<int>> list;

    int vector_length, temp;
    for (int i = 0; i < n; i++){
        cin >> vector_length;
        vector<int> temp_vec;
        for (int j = 0; j < vector_length; j++){
            cin >> temp;
            temp_vec.push_back(temp);
        }
        list.push_back(temp_vec);
    }

    // Now handle queries;
    int temp2;
    for (int i = 0; i < queries; i++){
        cin >> temp >> temp2;
        cout << list[temp][temp2] << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
