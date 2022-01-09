#include"Line.h"
#include<cmath>
#include <QDebug>
Line ::Line( string name ,string color , int fristx , int fristy , int x2 , int y2){

    Setlength(fristx,fristy,x2,y2);
    setColor(color);
    setName(name);
}
void Line:: Setlength(int x_f, int y_f, int x_s ,int y_s) {

    length = sqrt(pow((x_f-x_s),2) +pow((y_f-y_s),2));

}
double Line :: getperimeter() {
    return length ;
}
