#include"Circle.h"
Circle ::Circle(string name , string color , double radius , double perimeter){
Setradius(radius);
setName(name);
setColor(color);
Setperimeter(perimeter);
}
Circle::Circle(){}

    void Circle :: Setradius(double radius) {
       this-> radius = radius;
    }

    double Circle:: getradius() {
        return radius;
    }
    void  Circle:: Setperimeter(double radius) {
         perimeter = 2 * 3.14 * radius;
    }
    double Circle::getperimeter(){
      return perimeter ;
    }

