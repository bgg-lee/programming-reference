#include "prob3_a.hpp"

int main(void){
    Shape* shape1 = new Rectangle(2, 5);
    Shape* shape2 = new Circle(2);
    Shape* shape3 = new Circle(3);

    cout << shape1->get_area() << endl;
    cout << shape2->get_area() << endl;
    cout << shape3->get_area() << endl;
}