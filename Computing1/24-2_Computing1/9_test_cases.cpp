#include <iostream>
#include <vector>
#include <cmath>
#include "9_exercise.h"

using namespace std;

template<typename T>
bool compareVectors(const vector<T>& v1, const vector<T>& v2, T tolerance = static_cast<T>(1e-9)) {
    if (v1.size() != v2.size()) return false;
    for (size_t i = 0; i < v1.size(); ++i) {
        if constexpr (is_floating_point<T>::value) {
            if (abs(v1[i] - v2[i]) > tolerance) return false;
        } else {
            if (v1[i] != v2[i]) return false;
        }
    }
    return true;
}

bool runTests() {
    bool all_tests_passed = true;

    // Test case 1: Vectors of type int
    vector<int> v1_int = {1, 2, 3};
    vector<int> v2_int = {4, 5, 6};
    vector<int> expected_sum_int = {5, 7, 9};
    int expected_dot_product_int = 32;

    cout << "Test Case 1: int vectors\n";
    vector<int> result_int = addVectors(v1_int, v2_int);
    int dot_product_int = dotProduct(v1_int, v2_int);

    if (!compareVectors(result_int, expected_sum_int)) {
        cout << "Test Case 1 Failed: Incorrect vector sum.\n";
        all_tests_passed = false;
    } else if (dot_product_int != expected_dot_product_int) {
        cout << "Test Case 1 Failed: Incorrect dot product.\n";
        all_tests_passed = false;
    } else {
        cout << "Test Case 1 Passed.\n";
    }

    // Test case 2: Vectors of type float
    vector<float> v1_float = {1.1f, 2.2f, 3.3f};
    vector<float> v2_float = {4.4f, 5.5f, 6.6f};
    vector<float> expected_sum_float = {5.5f, 7.7f, 9.9f};
    float expected_dot_product_float = 38.72f;

    cout << "\nTest Case 2: float vectors\n";
    vector<float> result_float = addVectors(v1_float, v2_float);
    float dot_product_float = dotProduct(v1_float, v2_float);

    if (!compareVectors(result_float, expected_sum_float)) {
        cout << "Test Case 2 Failed: Incorrect vector sum.\n";
        all_tests_passed = false;
    } else if (abs(dot_product_float - expected_dot_product_float) > 1e-5) {
        cout << "Test Case 2 Failed: Incorrect dot product.\n";
        all_tests_passed = false;
    } else {
        cout << "Test Case 2 Passed.\n";
    }

    // Test case 3: Vectors of type double
    vector<double> v1_double = {1.1, 2.2, 3.3};
    vector<double> v2_double = {4.4, 5.5, 6.6};
    vector<double> expected_sum_double = {5.5, 7.7, 9.9};
    double expected_dot_product_double = 38.72;

    cout << "\nTest Case 3: double vectors\n";
    vector<double> result_double = addVectors(v1_double, v2_double);
    double dot_product_double = dotProduct(v1_double, v2_double);

    if (!compareVectors(result_double, expected_sum_double)) {
        cout << "Test Case 3 Failed: Incorrect vector sum.\n";
        all_tests_passed = false;
    } else if (abs(dot_product_double - expected_dot_product_double) > 1e-9) {
        cout << "Test Case 3 Failed: Incorrect dot product.\n";
        all_tests_passed = false;
    } else {
        cout << "Test Case 3 Passed.\n";
    }

    // Final test result summary
    if (all_tests_passed) {
        cout << "\nAll test cases passed.\n";
    } else {
        cout << "\nSome test cases failed.\n";
    }
    return all_tests_passed;
}


int main() {
    if (runTests()) {
        try {
            int type;

            cout << "\nDo the test yourself"<<endl;
            cout << "Choose type of the vectors (1: int, 2: float, 3: double): ";
            cin >> type;
            

            switch (type) {
                case 1:
                    /*============================================= TODO 5 =============================================
                        1. Instruction:
                        - Call the `processVectors` function with `int` as the template argument.
                    ====================================================================================================*/
                    // Your code here:
                    processVectors<int>();

                    break;
                case 2:
                    /*============================================= TODO 6 =============================================
                        1. Instruction:
                        - Call the `processVectors` function with `float` as the template argument.
                    ====================================================================================================*/
                    // Your code here:
                    processVectors<float>();
                    

                    break;
                case 3:
                    /*============================================= TODO 7 =============================================
                        1. Instruction:
                        - Call the `processVectors` function with `double` as the template argument.
                    ====================================================================================================*/
                    // Your code here:
                    processVectors<double>();
                    
                    
                    break;
                default:
                    cout << "잘못된 타입을 입력하셨습니다." << endl;
                    return 0;
            }
            } catch (const std::invalid_argument& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return 1;
        }
    } else {
        return 0;
    }
}
