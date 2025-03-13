/* OOP + Operator, Vector의 합,차,곱 등을 구현 */
#ifndef QE_PROB3_H
#define QE_PROB3_H

#include <iostream>
#include <cmath>

using namespace std;

// Base class for 2D vectors
class Vector2D {
    /*WRITE YOUR CODE HERE*/
// private:
//     double x;
//     double y;
public:
    double x;
    double y;
    // 초기화
    Vector2D(double x = 0.0,double y = 0.0):x(x),y(y){}
    
    void setX(double x_val) { x = x_val; }
    double getX() const { return x; }
    void setY(double y_val) { y = y_val; }
    double getY() const { return y; }

    Vector2D operator+(const Vector2D &other) const {
        return Vector2D(x + other.x , y + other.y);
    }

    Vector2D operator-(const Vector2D &other) const {
        return Vector2D(x - other.x , y - other.y);
    }

    Vector2D operator*(const Vector2D &other) const {
        return Vector2D(x * other.x , y * other.y);
    }
    Vector2D operator*(const double num) const {
        return Vector2D(x * num , y * num);
    }
    bool operator==(const Vector2D &other) const {
        return x==other.x && y==other.y;
    }
    void print(std::ostream &out){
        out << "Vector2D:" << x << "," << y;
    }
    /*
    꺽쇠관련 다 지우고 이 주석만 실행시켜도 된다. 이것저것 실험해본다고 이 주석 남겨놓음
    friend std::ostream &operator<<(std::ostream &out,const Vector2D &vec){
        out << "Vector2D(" << vec.x << ", " << vec.y << ")";
        return out;
    }
    void print() const {
        cout << *this << endl;
    }
    */
    // void print() const {
    //     cout<<"Vector2D(" << x << ", " << y << ")"<<endl;
    // } 이렇게 해도 무방
    virtual float magnitude() const;

    virtual Vector2D* normalize() const; // 포인터버전
    // virtual Vector2D normalize() const; // 일반버전
};
std::ostream &operator<<(std::ostream &out, Vector2D &vec){
    vec.print(out);
    return out;
}

float Vector2D::magnitude() const{
    return sqrt(pow(x,2)+pow(y,2));
}
Vector2D* Vector2D::normalize() const{ // 포인터버전
    if(this->magnitude()==0) return const_cast<Vector2D*>(this);
    // 희한하다.. normalize가 const로 되어 있으면 const_cast 해줘야 함.
    Vector2D* temp = new Vector2D(x/(this->magnitude()),y/(this->magnitude()));
    return temp;
}
// Vector2D Vector2D::normalize() const{ //일반객체 버전
//     if(this->magnitude()==0) return *this;
//     return Vector2D(x/this->magnitude(),y/this->magnitude());
// }

// Derived class for 3D vectors
class Vector3D : public Vector2D {
    /*WRITE YOUR CODE HERE */
private: double z;
public:
    Vector3D(double x_val = 0.0 ,double y_val = 0.0, double z_val = 0.0):Vector2D(x_val,y_val),z(z_val){}
    void setZ(double input_z){z=input_z;}
    double getZ(){return z;}

    Vector3D operator+(const Vector3D &other) const {
        return Vector3D(x + other.x , y + other.y, z + other.z);
    }

    Vector3D operator-(const Vector3D &other) const {
        return Vector3D(x - other.x , y - other.y,z-other.z);
    }

    Vector3D operator*(const Vector3D &other) const {
        return Vector3D(x * other.x , y * other.y, z*other.z);
    }
    Vector3D operator*(const double num) const {
        return Vector3D(x * num , y * num,z*num);
    }
    bool operator==(const Vector3D &other) const {
        return x==other.x && y==other.y && z==other.z;
    }
    friend std::ostream &operator<<(std::ostream &out,const Vector3D &vec){
        out << "Vector3D(" << vec.x << ", " << vec.y << ", "<<vec.z<<")";
        return out;
    }
    void print() const {
        cout << *this << endl;
    }
    float magnitude() const override{
        return sqrt(pow(x,2)+pow(y,2)+pow(z,2));
    }
    Vector3D* normalize() const override{ //override 해줘야 return 값 바꿀 수 있다
        if (this->magnitude() == 0) return new Vector3D(*this);
        return new Vector3D(x / this->magnitude(), y / this->magnitude(), z / this->magnitude());
    }
    // Pointer나 Reference type만 override를 통해 return type을 바꿀 수 있다.. 중요!

};

#endif



/* Reference로 Vector2D& 반환
class Vector2D {
protected:
    double x, y;

public:
    Vector2D(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    virtual float magnitude() const {
        return sqrt(x * x + y * y);
    }

    virtual Vector2D& normalize() const {
        static Vector2D temp; // 반환할 객체를 static으로 선언
        float mag = magnitude();
        if (mag == 0) {
            temp = *this; // 크기가 0일 경우, 자기 자신 반환
        } else {
            temp = Vector2D(x / mag, y / mag);
        }
        return temp;
    }
};

/*
friend 없이 << operator 사용
#include <iostream>

class Vector2D {
private:
    double x, y;

public:
    Vector2D(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    // Public getter methods
    double getX() const { return x; }
    double getY() const { return y; }

    // Optional: Print formatting inside a method
    void print(std::ostream &out) const {
        out << "Vector2D(" << x << ", " << y << ")";
    }
};

// Non-member operator<<
std::ostream &operator<<(std::ostream &out, const Vector2D &vec) {
    vec.print(out);  // Call public method to access private members
    return out;
}
*/

// class Vector3D : public Vector2D {
// private:
//     double z;

// public:
//     Vector3D(double x = 0.0, double y = 0.0, double z = 0.0) : Vector2D(x, y), z(z) {}

//     float magnitude() const override {
//         return sqrt(x * x + y * y + z * z);
//     }

//     Vector3D& normalize() const override {
//         static Vector3D temp; // 반환할 객체를 static으로 선언
//         float mag = magnitude();
//         if (mag == 0) {
//             temp = *this; // 크기가 0일 경우, 자기 자신 반환
//         } else {
//             temp = Vector3D(x / mag, y / mag, z / mag);
//         }
//         return temp;
//     }
// };










/*
SOLUTION 참고,
문제는 2d 기준으로 INHERIT 해서 3d를 구현하는 것

// I am creating a class vector3d which will be used for vector operation . I have overloaded all the basic functions for the required for vector operation .
// There is no need for extra class , so no inheritance was necessary .

#include<iostream>
#include<math.h>
#include<assert.h>
using namespace std;
typedef float f;
class vector3d
{
public:
    f x,y,z;
    vector3d()  //constructor
    {
        x=0;
        y=0;
        z=0;
    }

    vector3d(f x1,f y1,f z1=0)     //initializing object with values.
    {
        x=x1;
        y=y1;
        z=z1;
    }
    vector3d(const vector3d &vec);    //copy constructor
    vector3d operator+(const vector3d &vec);    //addition
    vector3d &operator+=(const vector3d &vec);  ////assigning new result to the vector
    vector3d operator-(const vector3d &vec);    //substraction
    vector3d &operator-=(const vector3d &vec);  //assigning new result to the vector
    vector3d operator*(f value);    //multiplication
    vector3d &operator*=(f value);  //assigning new result to the vector.
    vector3d operator/(f value);    //division
    vector3d &operator/=(f value);  //assigning new result to the vector
    vector3d &operator=(const vector3d &vec);
    f dot_product(const vector3d &vec); //scalar dot_product
    vector3d cross_product(const vector3d &vec);    //cross_product
    f magnitude();  //magnitude of the vector
    vector3d normalization();   //nor,malized vector
    f square(); //gives square of the vector

    f distance(const vector3d &vec);    //gives distance between two vectors
    f show_X(); //return x
    f show_Y(); //return y
    f show_Z(); //return z
    void disp();    //display value of vectors
};

vector3d::vector3d(const vector3d &vec)
{
    x=vec.x;
    y=vec.y;
    z=vec.z;
}

//addition

vector3d vector3d ::operator+(const vector3d &vec)
{
    return vector3d(x+vec.x,y+vec.y,z+vec.z);
}

vector3d &vector3d ::operator+=(const vector3d &vec)
{
    x+=vec.x;
    y+=vec.y;
    z+=vec.z;
    return *this;
}
//substraction//
vector3d vector3d ::operator-(const vector3d &vec)
{
    return vector3d(x-vec.x,y-vec.y,z-vec.z);
}

vector3d &vector3d::operator-=(const vector3d &vec)
{
    x-=vec.x;
    y-=vec.y;
    z-=vec.z;
    return *this;
}

//scalar multiplication

vector3d vector3d ::operator*(f value)
{
    return vector3d(x*value,y*value,z*value);
}



vector3d &vector3d::operator*=(f value)
{
    x*=value;
    y*=value;
    z*=value;
    return *this;
}

//scalar division
vector3d vector3d ::operator/(f value)
{
    assert(value!=0);
    return vector3d(x/value,y/value,z/value);
}

vector3d &vector3d ::operator/=(f value)
{
    assert(value!=0);
    x/=value;
    y/=value;
    z/=value;
    return *this;
}


vector3d &vector3d::operator=(const vector3d &vec)
{
    x=vec.x;
    y=vec.y;
    z=vec.z;
    return *this;
}

//Dot product
f vector3d::dot_product(const vector3d &vec)
{
    return x*vec.x+vec.y*y+vec.z*z;
}

//cross product
vector3d vector3d ::cross_product(const vector3d &vec)
{
    f ni=y*vec.z-z*vec.y;
    f nj=z*vec.x-x*vec.z;
    f nk=x*vec.y-y*vec.x;
    return vector3d(ni,nj,nk);
}

f vector3d::magnitude()
{
    return sqrt(square());
}

f vector3d::square()
{
    return x*x+y*y+z*z;
}

vector3d vector3d:: normalization()
{
    assert(magnitude()!=0);
    *this/=magnitude();
    return *this;
}

f vector3d::distance(const vector3d &vec)
{
    vector3d dist=*this-vec;
    return dist.magnitude();
}

f vector3d::show_X()
{
    return x;
}

f vector3d::show_Y()
{
    return y;
}

f vector3d::show_Z()
{
    return z;
}

void vector3d::disp()
{
    cout<<x<<" "<<y<<" "<<z<<endl;
}

int main()
{

    vector3d a=vector3d(2,5,7);
    vector3d b=vector3d(3,7,10);
    vector3d c=a+b;
    c.disp();
    //provide any operation.
}
*/