#include <iostream>
#include <cmath>

using namespace std;

//  추상 클래스: 도형의 기본 클래스
class Shape {
protected:
    string name;

public:
    Shape(string n) : name(n) {}
    virtual ~Shape() {}

    virtual double getArea() const = 0;  // 순수 가상 함수 (Abstract)
    
    //  `operator==` 오버로딩 (면적 비교)
    bool operator==(const Shape& other) const {
        return abs(getArea() - other.getArea()) < 1e-6;  // 부동소수점 비교
    }

    //  `operator<<` 오버로딩 (출력)
    friend ostream& operator<<(ostream& os, const Shape& shape) {
        os << shape.name << " (Area: " << shape.getArea() << ")";
        return os;
    }
};

//  `Rectangle` 클래스 (사각형)
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : Shape("Rectangle"), width(w), height(h) {}

    double getArea() const override {
        return width * height;
    }

    //  `operator+` 오버로딩 (면적 합산)
    Rectangle operator+(const Rectangle& other) const {
        return Rectangle(width + other.width, height + other.height);
    }

    //  `operator-` 오버로딩 (면적 차이 반환)
    double operator-(const Rectangle& other) const {
        return abs(getArea() - other.getArea());
    }
};

//  `Circle` 클래스 (원)
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : Shape("Circle"), radius(r) {}

    double getArea() const override {
        return M_PI * radius * radius;
    }
};

//  테스트 코드
int main() {
    Rectangle rect1(3, 4);
    Rectangle rect2(5, 6);
    Circle circle1(3);
    Circle circle2(4);

    cout << "Rect1: " << rect1 << endl;
    cout << "Rect2: " << rect2 << endl;

    cout << "Rect1 + Rect2: " << (rect1 + rect2) << endl;
    cout << "Rect1 - Rect2 (Area differ): " << (rect1 - rect2) << endl;

    cout << "Circle1: " << circle1 << endl;
    cout << "Circle2: " << circle2 << endl;
    cout << "Circle1 == Circle2? " << (circle1 == circle2 ? "True" : "False") << endl;

    return 0;
}
