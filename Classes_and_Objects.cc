/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/22/2020 at 01:04 PM
 *
 * Classes_and_Objects.cc
 *
 * -----------------------------------------------------------------------------
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

// Write your Student class here

class Student {
public:
    void input();
    int calculateTotalScore();
private:
    vector<int> scores{0, 0, 0, 0, 0};

};

void Student::input() {
    static int temp;
    for (int i = 0; i < 5; i++){
	cin >> temp;
	scores.at(i) = temp;
    }       
}

int Student::calculateTotalScore() {
    int sum = 0;
    for (int &i : scores)
	sum += i;
    
    return sum;
}

//------------------------------------------------------------------------------
// Do not EDIT THIS
//------------------------------------------------------------------------------
int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    delete[] s; // Don't forget to deallocate when you're done.
    return 0;
}
