//
// Created by ulysses on 7/5/19.
//
#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int sealevel, valley_num;
    sealevel = valley_num = 0;
    for (int i = 0; i < s.length(); i++){
        sealevel = (s[i] == 'D') ? sealevel + 1 : sealevel - 1;
        if (sealevel == 0 && (s[i] == 'U'))
            valley_num++;
    }
    return valley_num;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

