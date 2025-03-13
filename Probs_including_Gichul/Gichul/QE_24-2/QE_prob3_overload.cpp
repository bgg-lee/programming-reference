
/*
implement a class named Complex to represent complex numbers. A complex number is of the form a + bi where a and b are real numbers and i^2 = -1.
a is referred to as the real part of the complex number, and bi is the imaginary number.

Define a class named Complex with two private data members, real and imag of type double.
Implemen a constructor that takes two double arguments and initializes real and imag respectively, and the following member functions.
    double getReal(){}
    double getImag(){}
    void setReal(double _real){}
    void setImag(double _imag){}

implement an overloaded addition operator to return the sum of two Complex objects.
    a + bi addition c + di = (a+c) + (c+d)i

implement an overloaded negation operator (unary-) that will negate both the real and imaginary parts of a complex number
    negation (2+4i) = -2-4i

implement an overloaded << operator to print in a form of real + imag i. 
it rhe imaginary component is zero, output only the real component.
if the imaginary part is negative, replace + symbol with -.

you can only include followings.
    #include <iostream>
    #include <cstdio>
    #include <iomanip>
    #include <string>
    #include <cmath>

*/
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
class Complex{
private:
  double real;
  double imag;
public:
  Complex(double r = 0, double i = 0):real(r),imag(i){}
  double getReal(){return real;}
  double getImag(){return imag;}
  void setReal(double _real){real = _real;}
  void setImag(double _imag){imag = _imag;}

  Complex operator+(const Complex rhs) const{
    return Complex(real + rhs.real, imag + rhs.imag);
  }
  Complex operator-() const{
    return Complex(-real,-imag);
  }

  friend ostream& operator<<(ostream& out,const Complex rhs){
    out << rhs.real;
    if(rhs.imag == 0) return out;
    else if(rhs.imag > 0){
      out << "+" << rhs.imag << "i";
    }else{
      out << "-" << -rhs.imag << "i";
    }
    return out;
  }
};


int main() {
  cout << fixed;
  Complex c1(3.3, 2.6);

  Complex c2, c3;
  c2.setReal(7.89);
  c2.setImag(-9.21);

  c3 = c1 + c2;

  cout << "The Sum is " << c3 << endl;
  cout << "The Real part is " << c3.getReal() << endl;
  cout << "The Imag part is " << c3.getImag() << endl;

  cout << "Negation of c3: " << -c3 << endl;

  return 0;
}