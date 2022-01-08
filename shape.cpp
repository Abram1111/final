#include"Shape.h"
#include <iostream>
using namespace std;
#include <string>


    void Shape::setName(string n) {
        name = n;
    }
    string Shape:: getName() {
        return name;
    }
    void Shape:: setColor(string color) {
        this->color = color;
    }
    string Shape:: getColor() {
        return color;
    }
    void Shape:: setCenter_x(double x) {
        center_x = x;
    }
    double Shape:: getCenter_x() {
        return center_x;
    }void Shape:: setCenter_y(double y) {
        center_y = y;
    }
    double Shape:: getCenter_y() {
        return center_y;
    }



