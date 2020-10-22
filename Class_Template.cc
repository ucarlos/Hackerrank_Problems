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
    Traits(int val) : value{val} { convert_value(); }
    std::string get_name() { return nam; }
private:
    int value;
    T item;    
    std::string nam;    
    void convert_value();

};

template <typename T> void Traits<T>::convert_value(){
    nam = get_value(item, value);
}

int main(void){
    int test_cases;
    long color_value;
    long fruit_value;

    
    cin >> test_cases;
    for (int i = 0; i < test_cases; i++){
	cin >> color_value >> fruit_value;
	Traits<Color> color{static_cast<int>(color_value)};
	Traits<Fruit> fruit{static_cast<int>(fruit_value)};
	cout << color.get_name() << " " << fruit.get_name() << endl;
    }
}
