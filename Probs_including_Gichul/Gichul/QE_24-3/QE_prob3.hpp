// function overload inheritance 문제, 어지간하면 private class , const 이런 거 쓰지말자..

#ifndef QE_PROB3_H
#define QE_PROB3_H

#include <iostream>
#include <cmath>

using namespace std;
/*
문제예상,
    double x,y 를 private member로 <- double x,y para를 받는 생성자 만들어라
    getX,getY,setX,setY 만들고, operator +,-,*,==, << 만들어라.

    magnitude() , normalize() 만들어라 --> virtual로
    Vector3D에는 x,y,z를 받아서 inherit.
*/

// Base class for 2D vectors
class Vector2D {
private:
    double x;
    double y;
public:
    Vector2D(double input_x = 0,double input_y = 0):x(input_x),y(input_y){}
    double getX(){return x;}
    double getY(){return y;}
    void setX(double x_num) {x = x_num;}
    void setY(double y_num) {y = y_num;}
    virtual double magnitude() {return sqrt((x*x)+(y*y));}
    virtual Vector2D& normalize(){
        double mag = magnitude();
        setX(x/mag);
        setY(y/mag);
        return *this;
        // return Vector2D(x/magnitude(),y/magnitude());
    }
    Vector2D operator+(const Vector2D &rhs) const {
        return Vector2D(x+rhs.x,y+rhs.y);
    }
    Vector2D operator-(const Vector2D &rhs) const {
        return Vector2D(x-rhs.x,y-rhs.y);
    }
    Vector2D operator*(const Vector2D &rhs) const {
        return Vector2D(x*rhs.x,y*rhs.y);
    }
    bool operator==(const Vector2D &rhs) const {
        return x==rhs.x && y==rhs.y;
    }
    friend ostream& operator<<(ostream& out, Vector2D &rhs){
        out << "(" << rhs.getX() << "," << rhs.getY() << ")";
        return out;
    }
};

// Derived class for 3D vectors
class Vector3D : public Vector2D {
private :
    double z;
public :
    Vector3D(double x=0,double y=0, double z=0):z(z){
        setX(x);
        setY(y);
    }
    double getZ() {return z;}
    void setZ(double z_val){z=z_val;}
    double magnitude() override{return sqrt(pow(getX(),2)+pow(getY(),2)+pow(getZ(),2));}
    // override 함수는 return type이 pointer/reference인 거 아니면 꼭 base-derived 일치해야 한다.
    // 함수 이름, parameter 순서,개수,타입 다 맞아야함..
    Vector3D& normalize() override{
        setX(getX()/magnitude());
        setY(getY()/magnitude());
        setZ(z/magnitude());
        return *this;
    }
    // 함수 쓸 때, 내외적으로 const 맞춰줘야 한다.. 이게 굉장히 귀찮다.
    Vector3D operator+(Vector3D &rhs) {
        return Vector3D(getX()+rhs.getX(),getY()+rhs.getY(),z+rhs.getZ());
    }
    Vector3D operator-(Vector3D &rhs) {
        return Vector3D(getX()-rhs.getX(),getY()-rhs.getY(),z-rhs.getZ());
    }
    Vector3D operator*(Vector3D &rhs) {
        return Vector3D(getX()*rhs.getX(),getY()*rhs.getY(),z*rhs.getZ());
    }
    bool operator==(Vector3D rhs)  {
        return getX()==rhs.getX() && getY()==rhs.getY() && getZ() == rhs.getZ();
    }
    friend ostream& operator<<(ostream& out, Vector3D rhs){
        out << "(" << rhs.getX() << "," << rhs.getY() << "," << rhs.getZ() << ")";
        return out;
    }    

};

#endif
