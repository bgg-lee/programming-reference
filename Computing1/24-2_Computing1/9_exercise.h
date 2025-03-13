#ifndef EXERCISE_H
#define EXERCISE_H
#include <vector>
#include <stdexcept>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*=============================================== TODO 1 ===============================================
    1. Instruction:
        - Implement a function `addVectors`.
    2. Function Definition:
        - A template function that performs element-wise addition of two vectors of type T.
        - The function should be able to take vectors of any data type (e.g., int, float, double)
    3. Parameters:
        - First parameter: A constant reference to v1 of type vector<T>. This input vector remains unmodified.
        - Second parameter: A constant reference to v2 of type vector<T>. This input vector remains unmodified.
    4. Return:
        - It returns a new vector of type vector<T> containing the element-wise sum of `v1` and `v2`.
           Each element of the resulting vector is the sum of the corresponding elements from the input vectors.
    5. Preconditions:
        - Both input vectors `v1` and `v2` must be of the same size.
        - Hint: Use `throw invalid_argument("Vectors must have the same size.");`
=======================================================================================================*/
// Your code here:
template<typename T>
vector<T> addVectors(const vector<T> &v1,const vector<T> &v2){
    // Throw 적용
    if(v1.size()!=v2.size()){
        throw invalid_argument("Vectors must have the same size~~");
    }
    int n = v1.size();
    vector<T> temp;
    for(int i=0;i<n;i++){
        temp.push_back(v1[i]+v2[i]);
    }
    return temp;
}

/*=============================================== TODO 2 ===============================================
    1. Instruction:
        - Implement a function `dotProduct'.
    2. Function Definition:
        - A template function that computes the dot product of two vectors of type T.
        - The function should take vectors of any data type (e.g., int, float, double)
    3. Parameters:
        - First parameter: A constant reference to `v1` of type vector<T>. This is the first input vector, and it remains unmodified.
        - Second parameter: A constant reference to `v2` of type vector<T>. This is the second input vector, and it remains unmodified.
    4. Return:
        - It returns a value of type T, representing the dot product of the two input vectors.
          The dot product is computed by summing the products of corresponding elements from `v1` and `v2`.
    5. Preconditions:
        - Both input vectors `v1` and `v2` must be of the same size.
=======================================================================================================*/
// Your code here:
template<typename A>
A dotProduct(vector<A> &v1,vector<A> &v2){
    if(v1.size()!=v2.size()){
        throw invalid_argument("Vectors must have the same size!!");
    }
    int n = v1.size();
    A temp = 0;
    for(int i=0;i<n;i++){
        temp += (v1[i]*v2[i]);
    }
    return temp;
}

/*==================================== Do not modify this section =====================================*/
template<typename T>
vector<T> inputVector(const string& vectorName) {
    int size;
    vector<T> vec;
    cout << "Please enter the size of " << vectorName << ": ";
    cin >> size;
    if (size <= 0) {
        throw invalid_argument("The size of vector must be greater than 0");
    }
    cout << "Please enter the elements of " << vectorName << " (separate the elements with spaces and press Enter when you are done)." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string line;
    getline(cin, line);
    istringstream stream(line);
    
    for (int i = 0; i < size; ++i) {
        string valueStr;
        if (!(stream >> valueStr)) {
            throw invalid_argument("Invalid input detected! Expected type does not match.");
        }

        if constexpr (is_same<T, int>::value) {
            if (valueStr.find('.') != string::npos) {
                throw invalid_argument("Invalid input detected! Expected an integer, but received a floating-point number.");
            }

            char* end;
            long value = strtol(valueStr.c_str(), &end, 10);
            if (*end != '\0' || value > numeric_limits<int>::max() || value < numeric_limits<int>::min()) {
                throw invalid_argument("Invalid input detected! Expected an integer.");
            }

            vec.push_back(static_cast<int>(value));
        } else {
            istringstream valueStream(valueStr);
            T value;
            if (!(valueStream >> value) || !valueStream.eof()) {
                throw invalid_argument("Invalid input detected! Expected type does not match.");
            }
            vec.push_back(value);
        }
    }
    T extra;
    if (stream >> extra) {
        throw invalid_argument("Too many elements entered for " + vectorName + "! Expected " + to_string(size) + " values.");
    }
    return vec;
}
/*=====================================================================================================*/


template<typename T>
void processVectors() {
    vector<T> v1 = inputVector<T>("vector1");
    vector<T> v2 = inputVector<T>("vector2");

    /*=============================================== TODO 3 ===============================================
        1. Instruction:
            - Use the `addVectors` function to compute the element-wise sum of `v1` and `v2`.
            - Assign the result to a variable of type `vector<T>` named `result`.
            - Ensure that the return type of `addVectors` matches the type `vector<T>`.
    ======================================================================================================*/
    // your code here:
    vector<T> result = addVectors(v1,v2);

    /*==================================== Do not modify this section =====================================*/
    cout << "\nResult of `addVectors`: ";
    for (int i = 0; i < v1.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    /*============================================= TODO 4 =============================================
        1. Instruction:
            - Use the `dotProduct` function to compute the dot product of `v1` and `v2`.
            - Display the result of the `dotProduct` function using `cout` in the following format: "Result of `dotProduct`: ".
    ===================================================================================================*/
    // your code here:
    T result2 = dotProduct(v1,v2);
    cout << "Result of 'dotProduct': "<< result2 <<endl;
}

#endif
