/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/21/2020 at 11:31 PM
 *
 * Class_Template.cc
 * You are given a main function which reads the enumeration values for two
 * different types as input, then prints out the corresponding enumeration
 * names. Write a class template that can provide the names of the
 * enumeration values for both types. If the enumeration value is not valid,
 * then print unknown.
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <string>
using namespace std;

enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;


std::string get_value(enum Color, int value){
    switch(value){
    case 0:
	return "red";
    case 1:
	return "green";
    case 2:
	return "orange";
    default:
	return "unknown";
    }
}

std::string get_value(enum Fruit, int value){
    switch(value){
    case 0:
	return "apple";
    case 1:
	return "orange";
    case 2:
	return "pear";
    default:
	return "unknown";
    }
}

template <typename T> struct Traits {
public:
    Traits() =default;
    static std::string name(int val);
};

template <typename T> std::string Traits<T>::name(int val) {
    T item{};
    return get_value(item, val);
}

int main(void){
    int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }    
}
