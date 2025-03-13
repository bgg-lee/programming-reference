#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
using namespace std;

/*
Commands :
g++ -std=c++11 QE_prob3.cpp -o go.exe
./go.exe

Expected Output:
This is Rectangle, Its area is 8
This is Square, Its area is 16
This is Triangle, Its area is 3
This is RightTriangle, Its area is 6
*/

class Shape {
public:
    Shape(); 
    Shape(double w); 
    Shape(double w, double h); 
    Shape(double a, double b, double c);
    // virtual string get_name();
    string get_name();
    virtual double calc_area() = 0;

protected: 
    double w;
    double h;
    double c;
};

class Rectangle : public Shape {
public:
    Rectangle(double w, double h);
    double calc_area() override;
    // string get_name() override;
    string get_name();
};

class Square : public Rectangle {
public:
    Square(double w);
    // string get_name() override;
    string get_name();
};

class Triangle : public Shape {
public:
    Triangle(double a, double b, double c);
    double calc_area() override;
    // string get_name() override;
    string get_name();
};

class RightTriangle : public Triangle {
public:
    RightTriangle(double width, double height);
    // string get_name() override;
    string get_name();
};

Shape::Shape(){}
Shape::Shape(double w){
    this->w = w;
    this->h = w;
}
Shape::Shape(double w, double h){
    this->w = w;
    this->h = h;
}
Shape::Shape(double a, double b, double c){
    this->w = a;
    this->h = b;
    this->c = c;
}
string Shape::get_name(){ return "Shape";}

Rectangle::Rectangle(double w, double h) : Shape(w,h){};
string Rectangle::get_name(){ return "Rectangle";}
double Rectangle::calc_area(){
    return w*h;
}

Square::Square(double w) : Rectangle(w, w){};
string Square::get_name(){ return "Square";}

Triangle::Triangle(double a, double b, double c) : Shape(a, b, c){};
string Triangle::get_name(){ return "Triangle";}
double Triangle::calc_area(){
    double s = (w+h+c)/2;
    double area = sqrt(s*(s-w)*(s-h)*(s-c));
    return area;
}

RightTriangle::RightTriangle(double a, double b) : Triangle(a, b, sqrt(a*a+b+b)){};
string RightTriangle::get_name(){ return "RightTriangle";}

int main(void){
    Rectangle rectangle1(4.0, 2.0);
    printf("This is %s, Its area is %.f\n", rectangle1.get_name().c_str(), rectangle1.calc_area());
    
    Square square1(4.0);
    printf("This is %s, Its area is %.f\n", square1.get_name().c_str(), square1.calc_area()); 
    
    Triangle triangle1(4.0, 3.0, 2.0);
    printf("This is %s, Its area is %.f\n", triangle1.get_name().c_str(), triangle1.calc_area()); 
    
    RightTriangle righttriangle1(4.0, 3.0);
    printf("This is %s, Its area is %.f\n", righttriangle1.get_name().c_str(), righttriangle1.calc_area()); 

    // printf("----------------------\n");
    // Rectangle rectangle2(4.0, 5.0);
    // printf("This is %s, Its area is %.f\n", rectangle2.get_name().c_str(), rectangle2.calc_area());
    
    // Square square2(5.0);
    // printf("This is %s, Its area is %.f\n", square2.get_name().c_str(), square2.calc_area()); 
    
    // Triangle triangle2(8.0, 6.0, 4.0);
    // printf("This is %s, Its area is %.f\n", triangle2.get_name().c_str(), triangle2.calc_area()); 
    
    // RightTriangle righttriangle2(8.0, 6.0);
    // printf("This is %s, Its area is %.f\n", righttriangle2.get_name().c_str(), righttriangle2.calc_area()); 

    return EXIT_SUCCESS;
}