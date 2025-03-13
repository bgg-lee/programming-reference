
#ifndef QE_PROB3_H
#define QE_PROB3_H

#include <iostream>
#include <cmath>

using namespace std;

// Base class for 2D vectors
class Vector2D {
    public:
        
        Vector2D(double input_x, double input_y)
        {
            x=input_x;
            y=input_y;
        }
        
        float getX(){
            return x;
        }
        float getY(){
            return y;
        }

        void setX(double input_x){
            x=input_x;
        }
        void setY(double input_y){
            y=input_y;
        }

        Vector2D operator+(Vector2D asdf){
            Vector2D temp;
            temp.setX(x+asdf.x);
            temp.setY(y+asdf.y);
            return temp;
        }

        Vector2D operator-(Vector2D asdf){
            Vector2D temp;
            temp.setX(x-asdf.x);
            temp.setY(y-asdf.y);
            return temp;
        }

        Vector2D operator*(Vector2D asdf){
            Vector2D temp;
            temp.setX(x*asdf.x);
            temp.setY(y*asdf.y);
            return temp;
        }

        Vector2D operator==(Vector2D asdf){
            if(x==asdf.x && y==asdf.y){
                return 1;
            }
            else{
                return 0;
            }
        }

        void print(std::ostream& out = std::cout) const{
           out << "Vector2D(" << x << ", " << y << ")" << endl; 
        }

        virtual float magnitude() const;

        virtual Vector2D* normalize() const;
        

    private:
        double x, y;
};


std::ostream& operator<<(std::ostream& out, const Vector2D& cplx){
  //complex 클래스에 정의된 print 메서드를 호출하여 출력
  cplx.print(out);
  return out;
}

// Derived class for 3D vectors
class Vector3D : public Vector2D {
    /*

        WRITE YOUR CODE HERE
    
    */
};

#endif
