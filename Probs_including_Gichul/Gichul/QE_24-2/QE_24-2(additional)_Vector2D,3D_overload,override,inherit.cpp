#include "QE_prob3.hpp"
#include <iostream>
using namespace std;
int main() {
    // **Test Vector2D**
    Vector2D vec2D1(3, 4);
    Vector2D vec2D2(1, 2);

    cout << vec2D1 << endl;
    vec2D2.print(std::cout);


    // // Test +
    // Vector2D vec2D3 = vec2D1 + vec2D2;
    // std::cout << "vec2D1 + vec2D2: ";
    // vec2D3.print(); // Expected: (4, 6)

    // // Test -
    // Vector2D vec2D4 = vec2D1 - vec2D2;
    // std::cout << "vec2D1 - vec2D2: ";
    // vec2D4.print(); // Expected: (2, 2)

    // // Test *
    // Vector2D vec2D5 = vec2D1 * 2; // Scalar multiplication
    // std::cout << "vec2D1 * 2: ";
    // vec2D5.print(); // Expected: (6, 8)

    // // Test *
    // Vector2D vec2D5_1 = vec2D1 * vec2D2; // Scalar multiplication
    // std::cout << "vec2D1 * vec2D2: ";
    // vec2D5_1.print(); // Expected: (3, 8)

    // // Test ==
    // Vector2D vec2D6(3, 4);
    // if (vec2D1 == vec2D6) {
    //     std::cout << "vec2D1 is equal to vec2D6" << std::endl;
    // } else {
    //     std::cout << "vec2D1 is not equal to vec2D6" << std::endl;
    // }

    // // Test magnitude
    // std::cout << "Magnitude of vec2D1: " << vec2D1.magnitude() << std::endl; // Expected: 5

    // // // Test normalize -> 포인터 버전
    // // Vector2D* vec2D7 = vec2D1.normalize();
    // // std::cout << "Normalized vec2D1: ";
    // // vec2D7->print(); // Expected: (0.6, 0.8)

    // // Test normalize -> 일반버전
    // Vector2D* vec2D7 = vec2D1.normalize();
    // std::cout << "Normalized vec2D1: ";
    // vec2D7->print(); // Expected: (0.6, 0.8)

    // // **Test Vector3D**
    // Vector3D vec3D1(3, 4, 5);
    // Vector3D vec3D2(1, 2, 3);

    // // Test +
    // Vector3D vec3D3 = vec3D1 + vec3D2;
    // std::cout << "vec3D1 + vec3D2: ";
    // vec3D3.print(); // Expected: (4, 6, 8)

    // // Test -
    // Vector3D vec3D4 = vec3D1 - vec3D2;
    // std::cout << "vec3D1 - vec3D2: ";
    // vec3D4.print(); // Expected: (2, 2, 2)

    // // Test *
    // Vector3D vec3D5 = vec3D1 * 2; // Scalar multiplication
    // std::cout << "vec3D1 * 2: ";
    // vec3D5.print(); // Expected: (6, 8, 10)

    // // Test ==
    // Vector3D vec3D6(3, 4, 51);
    // if (vec3D1 == vec3D6) {
    //     std::cout << "vec3D1 is equal to vec3D6" << std::endl;
    // } else {
    //     std::cout << "vec3D1 is not equal to vec3D6" << std::endl;
    // }

    // // Test magnitude
    // std::cout << "Magnitude of vec3D1: " << vec3D1.magnitude() << std::endl; // Expected: sqrt(50)

    // // Test normalize
    // Vector3D* vec3D7 = vec3D1.normalize();
    // std::cout << "Normalized vec3D1: ";
    // vec3D7->print(); // Expected: normalized vector

    // std::cout << "All tests completed!" << std::endl;

    // return 0;
}
