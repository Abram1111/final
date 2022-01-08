#include"Rectangle.h"
Rectangl::Rectangl(string name , string color , double length , double width ){

Setlength(length);
Setwidth(width);
Setperimeter(width,length);
setName(name);
setColor(color);

}
    void Rectangl:: Setlength(double length) {
        this->length = length;
    }

    double Rectangl:: getlength() {
        return length;
    }
    void Rectangl:: Setwidth(double width) {
        this->width = width;
    }

    double Rectangl:: getwidth() {
        return width;
    }
    void Rectangl:: Setperimeter(double width, double length) {
         perimeter = 2 * (width + length);
    }

  //  double Rectangl:: getperimeter() {
    //    return perimeter ;
    //}
    double Rectangl:: getperimeter2() {
        return perimeter ;
    }
