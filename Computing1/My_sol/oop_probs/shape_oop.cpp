/*
Require : 
    - Abstract base class
    - Derived class
    - ShapeManager class
    - Demonstratino / Testing
    - (Optional) Operator overload, Exception, Dynamic Casting
Task :
    Shape(abstract class), Circle/Rectangle/Triangle
*/

#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <stdexcept>

//------------------------------------------------------
// 1) Abstract Base Class: Shape
//------------------------------------------------------
class Shape {
public:
    virtual ~Shape() {
        // Usually nothing needed here, but ensure it's virtual
    }

    // pure virtual methods => abstract class
    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    // optional virtual method
    virtual void printInfo() const {
        std::cout << "Generic Shape (no details)\n";
    }
};

//------------------------------------------------------
// 2) Derived Class: Circle
//------------------------------------------------------
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {
        if (r <= 0) {
            throw std::invalid_argument("Radius must be positive");
        }
    }

    double area() const override {
        // pi * r^2
        return M_PI * radius * radius;
    }

    double perimeter() const override {
        // 2 * pi * r
        return 2.0 * M_PI * radius;
    }

    void printInfo() const override {
        std::cout << "Circle(r=" << radius
                  << "), area=" << area()
                  << ", perimeter=" << perimeter() << "\n";
    }
};

//------------------------------------------------------
// 3) Derived Class: Rectangle
//------------------------------------------------------
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {
        if (w <= 0 || h <= 0) {
            throw std::invalid_argument("Width/Height must be positive");
        }
    }

    double area() const override {
        return width * height;
    }

    double perimeter() const override {
        return 2.0 * (width + height);
    }

    void printInfo() const override {
        std::cout << "Rectangle(w=" << width
                  << ", h=" << height
                  << "), area=" << area()
                  << ", perimeter=" << perimeter() << "\n";
    }
};

//------------------------------------------------------
// 4) Derived Class: Triangle
//------------------------------------------------------
class Triangle : public Shape {
private:
    double a, b, c;

public:
    // Construct triangle with sides a,b,c
    Triangle(double sideA, double sideB, double sideC)
        : a(sideA), b(sideB), c(sideC)
    {
        // check validity: each side < sum of other two
        if (a <= 0 || b <= 0 || c <= 0 ||
            (a + b <= c) || (b + c <= a) || (c + a <= b)) {
            throw std::invalid_argument("Invalid triangle side lengths");
        }
    }

    double area() const override {
        // Heron's formula
        double s = 0.5 * (a + b + c);
        return std::sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double perimeter() const override {
        return a + b + c;
    }

    void printInfo() const override {
        std::cout << "Triangle(a=" << a
                  << ", b=" << b
                  << ", c=" << c
                  << "), area=" << area()
                  << ", perimeter=" << perimeter() << "\n";
    }
};

//------------------------------------------------------
// 5) ShapeManager
//------------------------------------------------------
class ShapeManager {
private:
    std::vector<std::unique_ptr<Shape>> shapes;

public:
    // add shape
    void addShape(std::unique_ptr<Shape> shape) {
        shapes.push_back(std::move(shape));
    }

    // sum of all areas
    double totalArea() const {
        double sum = 0.0;
        for (const auto& s : shapes) {
            sum += s->area();
        }
        return sum;
    }

    // sum of all perimeters
    double totalPerimeter() const {
        double sum = 0.0;
        for (const auto& s : shapes) {
            sum += s->perimeter(); // s는 지금 unique_ptr이라서 -> 쓰는게 가능
        }
        return sum;
    }

    // print info of each shape
    void printAll() const {
        for (const auto& s : shapes) {
            s->printInfo();
        }
    }
};

//------------------------------------------------------
// 6) Main function (Example usage)
//------------------------------------------------------
int main() {
    ShapeManager manager;
    try {
        auto circle1 = std::make_unique<Circle>(5.0);
        auto rect1   = std::make_unique<Rectangle>(4.0, 2.5);
        auto tri1    = std::make_unique<Triangle>(3.0, 4.0, 5.0);

        manager.addShape(std::move(circle1));
        manager.addShape(std::move(rect1));
        manager.addShape(std::move(tri1));

        // print details of each shape
        manager.printAll();

        std::cout << "Total area = " << manager.totalArea() << "\n";
        std::cout << "Total perimeter = " << manager.totalPerimeter() << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Error creating shape: " << e.what() << "\n";
    }

    return 0;
}
