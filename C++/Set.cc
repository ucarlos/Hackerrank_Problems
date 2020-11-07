/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/31/2020 at 06:20 PM
 *
 * Set.cc
 *
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main(void){
    set<int> list;
    int max_queries;
    cin >> max_queries;

    int command, value;
    for (int i = 0; i < max_queries; i++){
	cin >> command >> value;
	if (command == 1)
	    list.insert(value);	    
	else if (command == 2) {
	    auto search = list.find(value);
	    if (search != list.end())
		list.erase(search);	    
	}
	else if (command == 3) {
	    auto search = list.find(value);
	    cout << (search != list.end()? "Yes" : "No") << endl;
	}
    }
}
