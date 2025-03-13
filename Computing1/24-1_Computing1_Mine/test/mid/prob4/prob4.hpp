#include <iostream>

template <typename T>
class BasicArray {
private:
    T* data;
    int size;

public:
    BasicArray(int initSize) : size(initSize) {
        data = new T[size];
    }

    ~BasicArray() {
        delete[] data; 
    }

    void set(int index, T value) {
        if (index >= 0 && index < size) {
            data[index] = value;
        }
    }

    T& operator[](int index) const { return data[index]; }
};
