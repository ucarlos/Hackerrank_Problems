/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 11/06/2020 at 06:09 PM
 *
 * Overload_Operators.cc
 *
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <stdexcept>
#include <cctype>
using namespace std;

struct Complex {
    int a, b;
    friend istream & operator>>(istream &is, Complex &c);
    friend ostream& operator<<(ostream &os, const Complex &c);
    Complex operator+(const Complex &b);
    
};

Complex Complex::operator+(const Complex &b){
    Complex temp = *this;
    
    temp.a += b.a;
    temp.b += b.b;

    return temp;
}

istream& operator>>(istream &is, Complex &complex) {
    int a, b, c;
    char temp;
    is >> a;

    // Now get the next character. If not + or -, raise error:
    is >> temp;

    if (temp != '+' && temp != '-') {
	const char *error = "Error: Complex number must add or subtract an "
	    "complex component.";
	throw runtime_error(error);
    }

    // Set the sign for b
    b = (temp == '+') ? 1 : -1 ;

    is >> temp;
    temp = tolower(temp);
    
    if (temp != 'i') // Must be in form a + ib, not a + bi (Unfortunately)
	throw runtime_error("Error: 'i' must come first before the value, like i10.");

    is >> c;
    b = b * c;

    complex.a = a;
    complex.b = b;
    
    return is;
}

ostream& operator<<(ostream &os, const Complex &c) {
    return os << c.a << ((c.b <= 0) ? "-" : "+") << "i" << c.b;
}

int main(void){
    Complex complex1, complex2;
    cin >> complex1 >> complex2;

    complex1 = complex1 + complex2;
    cout << complex1 << endl;       
}
