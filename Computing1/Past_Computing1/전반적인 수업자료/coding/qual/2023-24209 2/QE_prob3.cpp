#include <iostream>
#include <string>
#include <cmath>
using namespace std;
/*
--------------------------------------
How to compile:
g++ -std=c++11 -o prob3 QE_prob3.cpp

How to execute:
./prob3
--------------------------------------

Expected output:

name: Rectangle
area: 3.75

name: Square
area: 6.25

name: Triangle
area: 1.6238

name: RightTriangle
area: 10
*/

// (a)
class Shape{
    public:
        virtual string get_name()=0;
        virtual double calc_area() = 0;
};

// (b)
class Rectangle: public Shape{
    public:
        double w;
        double h;
        Rectangle(double width, double height):w(width), h(height){};
        virtual string get_name(){return "Rectangle";};
        virtual double calc_area(){return w*h;};
};

// (c)
class Square: public Rectangle{
    public:
        Square(double leng):Rectangle(leng, leng){};
        virtual string get_name(){return "Square";};
};

// (d)
class Triangle: public Shape{
    public:
        double a;
        double b;
        double c;
        Triangle(double A, double B, double C):a(A), b(B), c(C){};
        virtual string get_name(){return "Triangle";}
        double calc_area(){
            double s = (a+b+c)/2;
            double area;
            area = sqrt(s*(s-a)*(s-b)*(s-c));
            return area;
        }
};

// (e)
class RightTriangle: public Triangle{
    public:
        virtual string get_name(){return "RightTriangle";}
        RightTriangle(int width, int height):Triangle(width, height, sqrt(width*width + height*height)){}
};


int main(){

// (f)
Shape* rec = new Rectangle(1.5, 2.5);
Shape* tri = new Triangle(1.5, 2.5, 3.5);

Rectangle* sq = new Square(2.5);
Triangle* rig = new RightTriangle(4, 5);

// Constructor도 함수이긴 하지만, 
// instance를 선언할 때 자동으로 불리므로 더 명시적으로 call 할 필요는 없음.

// Rectangle
cout << "\nname: " << rec->get_name() << endl;
cout << "area: " << rec->calc_area() << endl;

// square
cout << "\nname: " << sq->get_name() << endl;
cout << "area: " << sq->calc_area() << endl;

// triangle
cout << "\nname: " << tri->get_name() << endl;
cout << "area: " << tri->calc_area() << endl;

// right triangle
cout << "\nname: " << rig->get_name() << endl;
cout << "area: " << rig->calc_area() << endl;


return 0;

}

