#ifndef RECTANGLE_H
#define RECTANGLE_H
#include"Shape.h"
class Rectangl : public Shape {

private:
    double length;
    double width;
    double perimeter;
public:
    Rectangl(string name , string color , double length , double width );
    void Setlength(double length) ;

    double getlength() ;
    void Setwidth(double width) ;

    double getwidth() ;
    void Setperimeter(double width, double length) ;
  //  double getperimeter() ;
    double getperimeter2();
};
#endif // RECTANGLE_H
