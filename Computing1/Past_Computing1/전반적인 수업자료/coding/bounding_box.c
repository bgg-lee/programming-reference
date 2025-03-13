#include <stdio.h>

typedef struct Point Point;
typedef struct Rectangle Rectangle;

struct Point{
    float x;
    float y;
} ;

struct Rectangle{
    Point a; // top-left
    Point b; // bottom-right
};

float area(Rectangle rect);
float width(Rectangle rect);
float height(Rectangle rect);
void midpoint(Rectangle rect);

int main(void){

    Point x = {3, 5};
    Point y = {7, 2};
    Rectangle rect = {x, y};

    printf("width: %f\n", width(rect));
    printf("height: %f\n", height(rect));
    printf("area: %f\n", area(rect));
    midpoint(rect);

}

float area(Rectangle rect){

    float w = width(rect);
    float h = height(rect);
    return w*h;
}
float width(Rectangle rect){
    Point A = rect.a;
    Point B = rect.b;

    if (A.x > B.x){
        return A.x-B.x;
    }
    else{return B.x-A.x;}

}
float height(Rectangle rect){
    Point A = rect.a;
    Point B = rect.b;

    if (A.y > B.y){
        return A.y-B.y;
    }
    else{return B.y-A.y;}
}
void midpoint(Rectangle rect){
    Point A = rect.a;
    Point B = rect.b;

    printf("x_axis midpoint: %f\n", (A.x + B.x)/2);
    printf("y_axis midpoint: %f\n", (A.y + B.y)/2);
}
