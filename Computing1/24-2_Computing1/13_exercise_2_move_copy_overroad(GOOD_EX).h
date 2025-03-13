#ifndef EXERCISE_H
#define EXERCISE_H

#include <iostream>
#include <cmath>
#include <initializer_list>
// #include <vector>
using namespace std;

template<typename T>
class Point {
private:
    T x, y;  

public:

    Point(T xVal = 0, T yVal = 0) : x(xVal), y(yVal) {

    }


    T getX() const { return x; }
    T getY() const { return y; }
    /*=============================================== TODO 1 ===============================================
        1. Instruction:
            - Implement a copy constructor for the Point class.
        2. Example:
            - When calling ```Point<int> p1(3, 4); Point<int> p2 = p1;```, p2 should be a copy of p1.
    =======================================================================================================*/
    // Move와 Copy Semantic을 위한 처사임
    Point(const Point& other) : x(other.x),y(other.y){
        std::cout << "Copy called" << std::endl;
    }

    /*=============================================== TODO 2 ===============================================
        1. Instruction:
            - Implement a move constructor for the Point class.
        2. Example:
            - When calling ```Point<int> p1(3, 4); Point<int> p2 = std::move(p1);```, 
              p2 should take the values from p1, and p1 should be reset.
    =======================================================================================================*/
    // Move만을 위한 only only!!! 생성자
    Point(Point&& other) noexcept : x(other.x),y(other.y){
        other.x = 0;
        other.y = 0;
        std::cout << "Move called" << std::endl;
    }
    /* 아, TODO 1~2 는 Constructor 단계부터 바로 Copy or Move하는 것
    TODO 3~4는 Point를 만들어 놓고, 그 다음 Copy or Move하는 것 */

    /*=============================================== TODO 3 ===============================================
        1. Instruction:
            - Implement the copy assignment operator for the Point class.
        2. Example:
            - When calling ```Point<int> p1(3, 4); Point<int> p2; p2 = p1;```,
              p2 should have the same values as p1.
    =======================================================================================================*/
    void operator=(const Point& other){
        x = other.x;
        y = other.y;
    }
    // // 모범답안
    // Point& operator=(const Point& other) {  
    // if (this != &other) {  // ✅ 자기 자신과의 대입 방지
    //     x = other.x;
    //     y = other.y;
    // }
    // return *this;
    // }
    /*=============================================== TODO 4 ===============================================
        1. Instruction:
            - Implement the move assignment operator for the Point class.
        2. Example:
            - When calling ```Point<int> p1(3, 4); Point<int> p2; p2 = std::move(p1);```, 
              p2 should take the values from p1, and p1 should be reset.
    =======================================================================================================*/
    // 이건 std::move 의 특징이 rvalue를 반환하기 때문에 Point&&로 표현한 것이다. Point && -> Reference를 2번 하면 rvalue, 1번이면 우리가 알던데로 lvalue를 뜻한다.
    Point& operator=(Point&& other) noexcept { 
        if(this != &other){
            x = other.x;
            y = other.y;
            other.x = 0;
            other.y = 0;
        }
        return *this;
    }
    /*=============================================== TODO 5 ===============================================
        1. Instruction:
            - Implement an assignment operator for the Point class using initializer list .
        2. Function Definition:
            - If the initializer list does not have exactly two elements, throw an invalid_argument exception.
              `` You must provide exactly 2 values (for x and y). ``
        3. Example:
            - When calling ```Point<int> p1; p1 = {3, 4};```, 
              p1 should have x = 3 and y = 4.
    =======================================================================================================*/
    Point& operator=(const std::initializer_list<T> lst){ // std::initializer_list<T>& 로 받으면 error catch 못함..
        if(lst.size()!=2){
            throw invalid_argument("You must provide exactly 2 values (for x and y).");
        }
        auto it = lst.begin();
        x = *it;
        it++;
        y = *it;
        return *this;
    }
    // 내 오답.. vector 이런 거 쓰는 게 아니라 initializer_list가 따로 있었다.
    // Point& operator=(const vector<T>& lst){
    //     int n = lst.size();
    //     x = lst[0];
    //     y = lst[1];
    //     return *this;
    // }
    /*=============================================== TODO 6 ===============================================
        1. Instruction:
            - Implement the [] operator to access the x or y coordinates using an index.
        2. Function Definition:
            - If the index is anything other than 0 or 1, throw an out_of_range exception.
              `` Index must be 0 or 1. ``
        3. Example:
            - p[0] should return the x coordinate, and p[1] should return the y coordinate.
    =======================================================================================================*/
//중요한 개념!!!!!!!!!!!!!!!!!!!!
    T& operator[](const int idx){ // Reference를 반환해야 rhs로 data 수정이 가능
        if(idx==0) return x;
        else if(idx==1) return y;
        else throw out_of_range("Index must be 0 or 1.");
    }

    // // 개판이다. operator[] 로 index 접근하는 걸 아예 몰랐음
    // void operator[](const int idx,const T& val){
    //     if(!(idx==0||idx==1)){
    //         throw out_of_range("Index must be 0 or 1.");
    //     }
    //     if(idx==0){
    //         x = val;
    //     }
    //     else y = val;
    // }

    /*=============================================== TODO 7 ===============================================
        1. Instruction:
            - Implement the * operator to calculate the dot product of two Point objects.
        2. Function Definition:
            - Return the result of the dot product calculation.
        3. Example:
            - When calling ```Point<int> p1(1, 2), p2(3, 4); int result = p1 * p2;```, the result should be 11.
    =======================================================================================================*/
    T operator*(const Point& other) const {
        return x * other.x + y * other.y;
    }
    // // 내 답안도 맞긴 했음
    // T operator*(const Point& other) const{
    //     T ans = 0;
    //     ans += (x*other.x);
    //     ans += (y*other.y);
    //     return ans;
    // }

    /*=============================================== TODO 8 ===============================================
        1. Instruction:
            - Implement the ^ operator to calculate the norm (length) of a Point object.
            - Support both the L1 norm and L2 norm.
        2. Function Definition:
            - L1 norm : |x| + |y|.
            - L2 norm : sqrt(x^2 + y^2).
            - If the norm type is not 1 or 2, throw an invalid_argument exception.
              `` Invalid norm type. Use 1 for L1 norm and 2 for L2 norm. ``
        3. Example:
            - When calling ```Point<int> p1(3, 4); double result = p1^2;```, the result should be 5.0.
    =======================================================================================================*/
    double operator^(int idx) const {
        if(idx==1) return abs(x)+abs(y);
        else if(idx==2) return sqrt(pow(x,2)+pow(y,2));
        else throw invalid_argument("Invalid norm type. Use 1 for L1 norm and 2 for L2 norm.");
    }

    // Return type을 T로 하니까 L2에서 걸리네 왜지..? Double로 하면 Pass -> T로하니까 root(5)가 2로 계산되어서 그런듯
    // T operator^(const int& idx) const{
    //     T ans = 0;
    //     if(idx==1){
    //         if(x>=0) ans += x;
    //         else ans -= x;
    //         if(y>=0) ans += y;
    //         else ans -= y;
    //         return ans;
    //     }
    //     else if(idx==2){
    //         return sqrt(x*x + y*y);
    //     }
    //     else throw invalid_argument("Invalid norm type. Use 1 for L1 norm and 2 for L2 norm.");
    // }

    
    /*=============================================== TODO 9 ===============================================
        1. Instruction:
            - Implement the != operator to check if two Point objects are not equal.
        2. Function Definition:
            - The != operator should return true if the x or y coordinates of the two points are different. 
            - Otherwise, it should return false.
        4. Example:
            - When calling ```Point<int> p1(3, 4); Point<int> p2(3, 5); bool result = (p1 != p2);```, 
              the result should be `true` because the `y` coordinates are different.
            - It should return `false` if both `x` and `y` are the same.
    =======================================================================================================*/
    bool operator!=(const Point& other) const {
        return x != other.x || y != other.y;
    }
    // // 나도 정답~
    // bool operator!=(const Point& other) const {
    //     if(x!=other.x || y!=other.y) return true;
    //     return false;
    // }



    /////////////// DO NOT MODIFY THIS ////////////////
    friend ostream& operator<<(ostream& os, const Point<T>& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }
    // // 걍 함 만들어 봄
    // friend ostream& operator<<(ostream& out, const Point<T>& point){
    //     out << "(" << point.x << "," << point.y << ")";
    //     return out;
    // }
    /////////////// DO NOT MODIFY THIS ////////////////
};



#endif 