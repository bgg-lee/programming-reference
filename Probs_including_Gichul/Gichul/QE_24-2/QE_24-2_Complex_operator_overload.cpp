#include <cstdio>
#include <iostream>
#include <ostream>
#include <cmath>

// class Complex {
// public:
// private:
//   double real, imag;
// };



#include <iostream>
#include <iomanip>
#include <cmath>

class Complex {
public:
    // Constructor
    Complex(double real = 0.0, double imag = 0.0) : real(real), imag(imag) {}

    // Getter and Setter for real and imaginary parts
    double getReal() const { return real; }
    void setReal(double r) { real = r; }

    double getImag() const { return imag; }
    void setImag(double i) { imag = i; }

    // Overloading + operator (binary)
    Complex operator+(const Complex &other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overloading - operator (unary)
    Complex operator-() const {
        return Complex(-real, -imag);
    }

    // Overloading << operator (output) //이게 좀 짜치네
    friend std::ostream &operator<<(std::ostream &out, const Complex &c) {
        // out << std::fixed << std::setprecision(2) << c.real;
        out << c.real;
        if (c.imag > 0)
            out << " + " << c.imag << "i";
        else if (c.imag < 0)
            out << " - " << -c.imag << "i";
        return out;
    }

private:
    double real, imag;
};

// Test code
int main() {
    std::cout << std::fixed << std::setprecision(2);
    Complex c1(3.3, 2.6);
    Complex c2, c3;
    c2.setReal(7.89);
    c2.setImag(-9.21);
    c3 = c1 + c2;

    std::cout << "The sum is " << c3 << std::endl;          // 11.19 - 6.61i
    std::cout << "The real is " << c3.getReal() << std::endl; // 11.19
    std::cout << "The imag is " << c3.getImag() << std::endl; // -6.61
    std::cout << "The negated sum is " << -c3 << std::endl;   // -11.19 + 6.61i

    Complex c4(1.0, 0.0);
    Complex c5(0.0, 1.0);
    Complex c6(-5, -7);
    Complex c7(0, -123.4567);

    std::cout << c4 << std::endl; // 1.00
    std::cout << c5 << std::endl; // 0.00 + 1.00i
    std::cout << c6 << std::endl; // -5.00 - 7.00i
    std::cout << c7 << std::endl; // 0.00 - 123.46i -> 반올림

    return 0;
}