/*
📝 Problem 2: SmartPointer - Implement a Custom Unique Pointer
Objective: Implement a simple smart pointer class with move semantics.

📌 Problem Statement
You need to implement a custom SmartPointer<T> class, which mimics std::unique_ptr<T>.
This smart pointer should manage a dynamically allocated object and ensure no memory leaks.

Requirements
Implement move semantics: SmartPointer should not allow copying but allow moving.
Overload operator* and operator-> to behave like a pointer.
Implement a destructor that automatically deletes the managed object.

*/
#include <iostream>

using namespace std;

template <typename T>
class SmartPointer {
private:
    T* ptr;

public:
    // ✅ Constructor
    explicit SmartPointer(T* p = nullptr) : ptr(p) {}

    // ✅ Destructor (Releases memory)
    ~SmartPointer() {
        delete ptr;
    }

    // ❌ Copy Constructor - Delete to prevent copying
    SmartPointer(const SmartPointer&) = delete;

    // ❌ Copy Assignment Operator - Delete to prevent copying
    SmartPointer& operator=(const SmartPointer&) = delete;

    // ✅ Move Constructor
    SmartPointer(SmartPointer&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    // ✅ Move Assignment Operator
    SmartPointer& operator=(SmartPointer&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    // ✅ Overload `operator*` (Dereference)
    T& operator*() { return *ptr; }

    // ✅ Overload `operator->` (Access members)
    T* operator->() { return ptr; }

    // ✅ Overload `operator bool()` (Check if SmartPointer is valid)
    explicit operator bool() const {
        return ptr != nullptr;
    }
};

// ✅ Sample class to test SmartPointer
class Test {
public:
    void show() { cout << "Test object method called!" << endl; }
};

int main() {
    SmartPointer<Test> sp1(new Test());
    sp1->show();  // Calls Test::show()

    // Move `sp1` to `sp2`
    SmartPointer<Test> sp2 = move(sp1);

    if (sp1) {  // ✅ Now this compiles!
        cout << "sp1 is still valid" << endl;
    } else {
        cout << "sp1 is null" << endl;
    }

    sp2->show();  // Still works
    return 0;
}
