/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 11/08/2020 at 05:35 PM
 *
 * Inheritance_Introduction.cc
 * One of the important topics of Object Oriented Programming is Inheritance.
 * Inheritance allows us to define a class in terms of another class, which
 * allows us in the re-usability of the code.
 *
 * The class Triangle has a function called triangle(). Now we create a
 * class derived from the base class Triangle called Isosceles.
 *
 * Now we can create a derived class object and use it to access the
 * functions of the base class.
 *
 * This code will print: { }
 * Now write a function in Isosceles class such that the output is as
 * given below.
 * -----------------------------------------------------------------------------
 */

#include <iostream>
using namespace std;

class Triangle {
public:
    void triangle() { cout << "I am a triangle\n"; }
    
};

class Isosceles : public Triangle {
public:
    void isoceles() { cout << "I am an isosceles triangle\n"; }
    void description() { cout << "In an isosceles triangle two sides are equal\n"; }
};

int main(void){
    Isosceles iso;
    iso.isoceles();
    iso.description();
    iso.triangle();
}
