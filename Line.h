#ifndef LINE_H
#define LINE_H
#include"Shape.h"
class Line : public Shape {

private:
    double length;
public:
    Line (string name,string color, int fristx , int fristy , int x2 , int y2);
    void Setlength(int x_f, int y_f, int x_s ,int y_s) ;
    double getlength() ;
    double getperimeter2();
};
#endif // LINE_H
