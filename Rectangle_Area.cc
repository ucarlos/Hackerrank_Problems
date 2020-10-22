/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/22/2020 at 12:29 AM
 *
 * Rectangle_Area.cc
 *
 * -----------------------------------------------------------------------------
 */

#include <iostream>
using namespace std;

class Rectangle {
public:
    Rectangle() =default;
    Rectangle(int w, int h) : width{w}, height{h} { }
    virtual void display() { std::cout << width << " " << height << "\n"; }
    int get_width() { return width; }
    int get_height() { return height; }
    void read_input();
private:
    int width{0};
    int height{0};
};


void Rectangle::read_input() {
    int width, height;
    cin >> width >> height;
    this->width = width;
    this->height = height;
}

class RectangleArea : public Rectangle {
public:
    RectangleArea() =default;
    RectangleArea(int w, int h) : Rectangle(w, h) { }
    void display() override { std::cout << get_width() * get_height()
					<< "\n"; }
};


int main(void){
    RectangleArea rect;
    rect.read_input();
    rect.Rectangle::display();
    rect.display();

}
