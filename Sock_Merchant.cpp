//
// Created by ulysses on 7/5/19.
//

#include "Sock_Merchant.h"
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the sockMerchant function below.
int sockMerchant(int input, vector<int> ar) {
    int pair = 0, temp;
    for (int i = 0; i < ar.size(); i++){
        temp = 1;
        for (int j = i + 1; j < ar.size(); j++){
            if (ar[j] == ar[i]){
                temp++;
                ar.erase(ar.begin() + j);
                --j;
            }
        }
        pair += (temp / 2);
    }
    return pair;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int input;
    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split_string(ar_temp_temp);

    vector<int> ar(input);

    for (int i = 0; i < input; i++) {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = sockMerchant(input, ar);

    fout << result << "\n";

    fout.close();
    cout << result << endl;


    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
