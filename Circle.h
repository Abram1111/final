#ifndef CIRCLE_H
#define CIRCLE_H
#include"Shape.h"
class Circle : public Shape {

private:
    double radius;
      double perimeter;
public:
      Circle(string name , string color , double radius , double perimeter);
      Circle();
    void Setradius(double radius) ;
    double getperimeter2();
    double getradius() ;
    void Setperimeter(double radius) ;
   // double getperimeter() ;



};
#endif // CIRCLE_H
