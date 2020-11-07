/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/31/2020 at 04:56 PM
 *
 * Lower_Bound_STL.cc
 *
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int list_len;
    vector<int> list;
    cin >> list_len;

    int temp;
    for (int i = 0; i < list_len; i++){
	cin >> temp; list.push_back(temp);
    }

    int queries;

    cin >> queries;
    for (int i = 0; i < queries; i++){
	cin >> temp;
	auto check = lower_bound(list.begin(), list.end(), temp);
	if (*check == temp)
	    cout << "Yes " << (check - list.begin()) + 1 << endl;
	else
	    cout << "No " << (check - list.begin()) + 1 << endl;
    }
}
