/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 11/02/2020 at 03:50 PM
 *
 * Print_Pretty.cc
 *
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int T; cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while(T--) {
	double A; cin >> A;
	double B; cin >> B;
	double C; cin >> C;

	/* Enter your code here */
	cout << nouppercase;
	cout << hex << left << showbase << static_cast<long long>(A) << endl;		
	cout << dec << noshowbase << right << setw(15) << setfill('_');
	cout << fixed << setprecision(2) << showpos << B << endl;

	cout << uppercase;
	cout << noshowpos << scientific << setprecision(9);
	cout << C << endl;

    }
    
    return 0;
}
