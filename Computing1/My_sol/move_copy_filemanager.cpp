/* Move copy 정리
class MyClass {
public:
    // 복사 생성자 
    MyClass(const MyClass& other) {
        // 깊은 복사 수행
    }

    // 이동 생성자
    MyClass(MyClass&& other) noexcept {
        // 리소스 이동
        // other의 리소스를 null로 설정
    }
    // 복사 대입 연산자
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            // 깊은 복사 수행
        }
        return *this;
    }
    // 이동 대입 연산자
    MyClass& operator=(MyClass&& other) noexcept {
        if (this != &other) {
            // 리소스 이동
            // other의 리소스를 null로 설정
        }
        return *this;
    }
};

int main(){
// -------  Construct case
MyClass a;

// 복사 생성
MyClass b(a);              // 복사 생성자
MyClass c = a;             // 복사 생성자

// 이동 생성
MyClass d(std::move(a));   // 이동 생성자
MyClass e = std::move(b);  // 이동 생성자
MyClass f = MyClass();     // 이동 생성자 (임시 객체)

// ------- Assign case
MyClass a, b;
MyClass c;

// 복사 대입
a = b;  // b는 lvalue이므로 복사 대입 연산자 호출

// 이동 대입
c = std::move(a);  // std::move(a)는 rvalue이므로 이동 대입 연산자 호출
c = MyClass();     // 임시 객체는 rvalue이므로 이동 대입 연산자 호출}

*/


/*
🚀 Advanced C++ Move & Copy Semantics Practice
Problem Title: "Implementing a Resource Managing Class (FileManager)"
Difficulty Level: 🔥🔥🔥 (Intermediate to Advanced)

📌 Problem Statement
You are developing a file management system where each FileManager object manages a file resource.
Since managing file resources is expensive, we must implement efficient memory management using move semantics.

📌 Requirements
Implement a FileManager class that manages a file descriptor (FILE*).
Implement the "Rule of Five":
Destructor (~FileManager()) → Closes the file.
Copy Constructor (FileManager(const FileManager&)) → Prevent copying.
Copy Assignment Operator (operator=) → Prevent copying.
Move Constructor (FileManager(FileManager&&) noexcept) → Transfer ownership.
Move Assignment Operator (operator=) → Transfer ownership.
Overload operator<< to print file status.
Allow only move operations to prevent accidental expensive copies.
--> copy construct / assignment도 허용하는 걸로 바꿔보자..! 공부를 위해
*/
#include <iostream>
#include <fstream>

using namespace std;

class FileManager {
private:
    FILE* file;
    string filename;

public:
    // ✅ Constructor
    FileManager(const string& fname, const string& mode = "w") : filename(fname) {
        file = fopen(fname.c_str(), mode.c_str());
        if (!file) {
            cerr << "Failed to open file: " << filename << endl;
        } else {
            cout << "File opened: " << filename << endl;
        }
    }

    // // ❌ Copy Constructor - Prevent copying
    // FileManager(const FileManager& other) = delete;
    
    FileManager(const FileManager& other) : filename(other.filename) {
        file = fopen(filename.c_str(),"w"); // write모드만 있다고 가정정
        if (!file) {
            cerr << "Failed to open file in copy constructor: " << filename << endl;
        } else {
            cout << "File copied: " << filename << endl;
        }
    }
    // ❌ Copy Assignment Operator - Prevent copying
    // FileManager& operator=(const FileManager& other) = delete;

    FileManager& operator=(const FileManager& other){
        if(this != &other){
            closeFile();
            filename = other.filename;
            file = fopen(filename.c_str(), "w");  // ✅ Always open in write mode
    
            if (!file) {
                cerr << "Failed to open file in copy assignment: " << filename << endl;
            } else {
                cout << "File copied via assignment: " << filename << endl;
            }            
        }
        return *this;
    }

    // ✅ Move Constructor // 더블 reference..
    FileManager(FileManager&& other) noexcept : file(other.file), filename(move(other.filename)) {
        other.file = nullptr;
        cout << "FileManager moved constructor : " << filename << endl;
    }

    // ✅ Move Assignment Operator
    FileManager& operator=(FileManager&& other) noexcept { // variable && -> move로 구분?
        if (this != &other) {
            closeFile();  // Close current file if open
            file = other.file;
            filename = move(other.filename);
            other.file = nullptr;
            cout << "FileManager moved via assignment: " << filename << endl;
        }
        return *this;
    }

    // ✅ Destructor
    ~FileManager() {
        closeFile();
    }

    // ✅ Overload `operator<<` for printing file status
    friend ostream& operator<<(ostream& os, const FileManager& fm) {
        if (fm.file) {
            os << "FileManager managing: " << fm.filename;
        } else {
            os << "FileManager has no open file.";
        }
        return os;
    }

private:
    void closeFile() {
        if (file) {
            fclose(file);
            cout << "File closed: " << filename << endl;
        }
    }
};

// ✅ Testing Move Semantics
int main() {
    FileManager fm1("111.txt");
    FileManager fm2("222.txt");
    FileManager fm3("333.txt");
    cout<<fm1<<"/ "<<fm2<<"/ "<<fm3<<endl;
    // copy assign
    fm1 = fm3;
    // move assign
    fm2 = move(fm3);
    cout<<fm1<<"/ "<<fm2<<"/ "<<fm3<<endl;


    // cout << fm1 << endl;
    // cout << fm2 << endl;
    // cout << endl;
    // // ✅ Move Constructor Test
    // FileManager fm3 = move(fm1);
    // cout << "After move, fm1: " << fm1 << endl;
    // cout << "After move, fm3: " << fm3 << endl;
    // cout << endl;
    // // ✅ Move Assignment Operator Test
    // fm2 = move(fm3);
    // cout << "After move assignment, fm2: " << fm2 << endl;
    // cout << "After move assignment, fm3: " << fm3 << endl;

    // Copy construct
    // FileManager fm4 = fm2;
    // cout << "After copy construct, fm2: " << fm2 << endl;
    // cout << "After copy construct, fm4: " << fm4 << endl;

    // FileManager fm44("CPP.txt");
    // cout << "Before copy assign, fm44: " << fm44 << endl;    
    // fm44 = fm2;
    // cout << "After copy assign, fm2: " << fm2 << endl;
    // cout << "After copy assign, fm44: " << fm44 << endl;    

    return 0;
}

