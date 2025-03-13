#include "prob3_b.hpp"
#include <string.h>

int main(void){
    Shape* shape1 = new Rectangle(2, 5);
    Shape* shape2 = new Circle(2.5);
    Shape* shape3 = new Circle(3);

    cout << Shape::n_shape << endl;

    delete shape2;
    delete shape3;
    cout << Shape::n_shape;

}