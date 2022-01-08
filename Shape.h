#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
using namespace std;
#include <string>

class Shape {
private:
    string name;
    string color;
    double center_x;
    double center_y;
public:

    void setName(string n);
    string getName();
    void setColor(string color);
    string getColor() ;
    void setCenter_x(double x) ;
    double getCenter_x();
    void setCenter_y(double y) ;
    double getCenter_y() ;
    virtual double getperimeter2()=0;
    //void delete(Shape);


};
#endif // SHAPE_H
