#include <iostream>
#include "QE_prob3.hpp"
using namespace std;


int main(){
    // Vector2D vec2 = Vector2D(3,4);
    // // cout<< "Vec x : " << vec2.getX() << " Vec y: " <<vec2.getY() <<endl;
    // // vec2.setX(4);
    // // vec2.setY(3);
    // // cout<< "After set, Vec x : " << vec2.getX() << " Vec y: " <<vec2.getY() <<endl;
    // Vector2D vec3;
    // vec3.setX(1.5);
    // vec3.setY(2.7);
    // cout<<"v2:"<<vec2<<", v3:"<<vec3 << endl;
    // Vector2D vec4 = vec2+vec3;
    // cout << "+:" << vec4 << endl;
    // vec4 = vec2-vec3;
    // cout << "-:" << vec4<< endl;
    // vec4 = vec2*vec3;
    // cout << "*:" << vec4<< endl;
    // cout << "v2 mag:" << vec2.magnitude() << endl;
    // cout << "v2 normalize: " << vec2.normalize() << endl;
    // Vector2D vec5(3,4);
    // if(vec5==vec2) cout << "== pass" << endl;
    Vector3D vec(3,4,5);
    cout << vec.getX() << ","<< vec.getY() << ","<< vec.getZ()<<endl;
    cout << vec.magnitude()<<endl;
    Vector3D vec2(-1,6,8);
    cout << vec2 << endl;
    cout << vec+vec2 << endl;    
    cout << vec-vec2 << endl;    
    cout << vec*vec2 << endl;    
    cout << vec.normalize() << endl;
    cout << vec;
    cout << "\nTest Completed" << endl;
}