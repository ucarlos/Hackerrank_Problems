/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/31/2020 at 07:34 PM
 *
 * Map.cc
 *
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
    map<std::string, int32_t> list;
    int max_queries;
    cin >> max_queries;

    int command, value;
    std::string student;
    for (int i = 0; i < max_queries; i++) {
	cin >> command >> student;

	if (command == 1) {
	    cin >> value;
	    list[student] += value;
	}
	else if (command == 2)
	    list.erase(student);
	else { // Command == 3
	    auto search = list.find(student);
	    cout << (search != list.end() ? search->second : 0) << endl;
	}
    }
}
