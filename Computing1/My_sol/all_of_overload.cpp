/*
#include <iostream>
using namespace std;

template<typename T>
class ComplexNumber{
private:
    T real;
    T imag;
public:
    //생성자
    ComplexNumber(T r = 0, T i = 0): real(r),imag(i){} // 초기화 지정 필요

    ComplexNumber<T> operator+(const ComplexNumber<T>& other) const{
        return ComplexNumber<T>(real+other.real, imag+other.imag);
    }
    ComplexNumber<T> operator-(const ComplexNumber<T>& other) const{
        return ComplexNumber<T>(real - other.real, imag - other.imag);
    }
    ComplexNumber<T> operator*(const ComplexNumber<T>& other) const{
        return ComplexNumber<T>(real * other.real - imag * other.imag,
            real * other.imag + imag * other.real);
    }
    bool operator==(const ComplexNumber<T>& other)const{
        return real == other.real && imag == other.imag ;
    }
    friend istream& operator>>(istream& is, ComplexNumber<T>& c){
        is >> c.real >> c.imag;
        return is;
    }
    friend ostream& operator<<(ostream& os, const ComplexNumber<T>& c){
        if(c.imag>0){
            os << c.real << "+" << c.imag << "i";
        }
        else{
            os << c.real << "-" << -c.imag << "i";
        }
        return os;
    }
    // ---------------------------
    //  아래가 새로 추가된 부분
    // ---------------------------

    // (1) 단항 부정: -num
    //     => 실수부/허수부 모두 부호 반전한 새 복소수 반환
    ComplexNumber<T> operator-() const {
        return ComplexNumber<T>(-real, -imag);
    }

    // (2) Prefix ++ ( ++num )
    //     => 현재 객체의 실수부/허수부를 1씩 증가 후, *this를 참조로 반환
    ComplexNumber<T>& operator++() {
        ++real;
        ++imag;
        return *this;
    }

    // (3) Postfix ++ ( num++ )
    //     => 현재 객체의 복사본 temp를 만든 뒤,
    //        자신을 1씩 증가하고 (실수/허수),
    //        temp를 반환
    ComplexNumber<T> operator++(int) {
        ComplexNumber<T> temp(*this);
        real++;
        imag++;
        return temp; 
    }

    // (4) Prefix -- ( --num )
    ComplexNumber<T>& operator--() {
        --real;
        --imag;
        return *this;
    }

    // (5) Postfix -- ( num-- )
    ComplexNumber<T> operator--(int) {
        ComplexNumber<T> temp(*this);
        real--;
        imag--;
        return temp;
    }
    // 추 추 추 추 가
    // += 연산자
    ComplexNumber<T>& operator+=(const ComplexNumber<T>& other) {
        real += other.real;
        imag += other.imag;
        return *this; // 자기 자신을 참조로 반환
    }

    // -= 연산자
    ComplexNumber<T>& operator-=(const ComplexNumber<T>& other) {
        real -= other.real;
        imag -= other.imag;
        return *this;
    }

    // *= 연산자
    ComplexNumber<T>& operator*=(const ComplexNumber<T>& other) {
        T r = real * other.real - imag * other.imag;
        T i = real * other.imag + imag * other.real;
        real = r;
        imag = i;
        return *this;
    }

    // /= 연산자 (복소수 ÷ 복소수)
    ComplexNumber<T>& operator/=(const ComplexNumber<T>& other) {
        // (a+bi)/(c+di) = ((ac+bd) + (bc−ad)i) / (c^2+d^2)
        T denominator = other.real * other.real + other.imag * other.imag;
        T r = (real * other.real + imag * other.imag) / denominator;
        T i = (imag * other.real - real * other.imag) / denominator;
        real = r;
        imag = i;
        return *this;
    }
};

int main(){
    ComplexNumber<double> a(3.5,2.1);
    ComplexNumber<double> b(1.5,4.0);
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;

    // (1) 단항 부정 테스트
    cout << "-a   = " << -a << endl;  // (실수부와 허수부가 모두 반전됨)

    // (2) prefix ++ 테스트
    cout << "++a  = " << ++a << endl;  // a를 먼저 증가시킨 후 변경된 값 출력
    // (3) postfix ++ 테스트
    cout << "a++  = " << a++ << endl;  // a의 이전 상태 출력, 이후 a는 증가
    cout << "a    = " << a << endl;    // a가 증가된 상태인지 확인

    // (4) prefix -- 테스트
    cout << "--b  = " << --b << endl;  // b를 먼저 감소시킨 후 변경된 값 출력
    // (5) postfix -- 테스트
    cout << "b--  = " << b-- << endl;  // b의 이전 상태 출력, 이후 b는 감소
    cout << "b    = " << b << endl;    // b가 감소된 상태인지 확인
    return 0;
}
*/


// 생성자 추가버전
#include <iostream>
#include <stdexcept> // for std::out_of_range, if 사용
using namespace std;

template<typename T>
class ComplexNumber {
private:
    T real;
    T imag;

public:
    // (A) 생성자
    ComplexNumber(T r = 0, T i = 0) : real(r), imag(i) {}

    // ------------------------------------
    // (B) 복사 생성자 (Copy Constructor)
    //     같은 타입의 다른 복소수 객체로부터 새 객체 생성
    ComplexNumber(const ComplexNumber<T>& other)
        : real(other.real), imag(other.imag) {
        // 필요시 deep copy (여기서는 단순 멤버 복사)
    }

    // (C) 이동 생성자 (Move Constructor)
    //     임시 객체(Rvalue)로부터 자원을 가져올 때 호출 --> && deference 2회 들어감;
    ComplexNumber(ComplexNumber<T>&& other) noexcept
        : real(std::move(other.real)), imag(std::move(other.imag)) {
        // other를 적절히 처리할 필요가 있으면 여기서 해도 됨
        // 하지만 단순 POD 멤버이므로 이 정도면 충분
    }

    // ------------------------------------
    // (D) 복사 대입 연산자 (Copy Assignment Operator)
    ComplexNumber<T>& operator=(const ComplexNumber<T>& other) {
        if (this != &other) { // 자기 자신이 아닌 경우만
            real = other.real;
            imag = other.imag;
        }
        return *this;
    }

    // (E) 이동 대입 연산자 (Move Assignment Operator)
    ComplexNumber<T>& operator=(ComplexNumber<T>&& other) noexcept {
        if (this != &other) {
            real = std::move(other.real);
            imag = std::move(other.imag);
        }
        return *this;
    }

    // ------------------------------------
    // (F) 사칙연산 연산자 (기존과 동일)
    ComplexNumber<T> operator+(const ComplexNumber<T>& other) const {
        return ComplexNumber<T>(real + other.real, imag + other.imag);
    }
    ComplexNumber<T> operator-(const ComplexNumber<T>& other) const {
        return ComplexNumber<T>(real - other.real, imag - other.imag);
    }
    ComplexNumber<T> operator*(const ComplexNumber<T>& other) const {
        return ComplexNumber<T>(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }
    // 만약 / 연산자도 원하시면 추가해보세요
    // ComplexNumber<T> operator/(const ComplexNumber<T>& other) const { ... }

    bool operator==(const ComplexNumber<T>& other) const {
        return (real == other.real) && (imag == other.imag);
    }

    // ------------------------------------
    // (G) 단항 부정(-), 증감 연산자(++/--)
    //     (필요시 참고 - 이전 예시와 동일)
    ComplexNumber<T> operator-() const {
        return ComplexNumber<T>(-real, -imag);
    }
    // prefix ++
    ComplexNumber<T>& operator++() {
        ++real; 
        ++imag;
        return *this;
    }
    // postfix ++
    ComplexNumber<T> operator++(int) {
        ComplexNumber<T> temp(*this);
        real++; 
        imag++;
        return temp;
    }
    // prefix --
    ComplexNumber<T>& operator--() {
        --real; 
        --imag;
        return *this;
    }
    // postfix --
    ComplexNumber<T> operator--(int) {
        ComplexNumber<T> temp(*this);
        real--; 
        imag--;
        return temp;
    }

    // ------------------------------------
    // (H) operator[] 오버로드
    //     0 => real, 1 => imag.
    //     유효 범위 밖이면 예외 처리(선택)
    T& operator[](size_t idx) {
        if (idx == 0)      return real;
        else if (idx == 1) return imag;
        throw std::out_of_range("Index must be 0 or 1");
    }
    // const 버전
    const T& operator[](size_t idx) const {
        if (idx == 0)      return real;
        else if (idx == 1) return imag;
        throw std::out_of_range("Index must be 0 or 1");
    }

    // ------------------------------------
    // (I) 입출력 연산자 (friend)
    friend std::istream& operator>>(std::istream& is, ComplexNumber<T>& c) {
        return (is >> c.real >> c.imag);
    }
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber<T>& c) {
        if (c.imag >= 0)
            os << c.real << "+" << c.imag << "i";
        else
            os << c.real << "-" << -c.imag << "i";
        return os;
    }
};

int main() {
    // 간단 테스트
    ComplexNumber<double> a(3.5, 2.1);
    ComplexNumber<double> b(1.5, 4.0);

    // (1) copy constructor
    ComplexNumber<double> c(a);       // c는 a를 복사
    // (2) move constructor
    ComplexNumber<double> d(std::move(b)); // b를 d로 이동(간단 예)

    // (3) copy assignment
    c = a;               // c에 a를 복사 대입
    // (4) move assignment
    c = std::move(d);    // c에 d를 이동 대입

    // (5) operator[] 테스트
    c[0] = 10; // real 변경
    c[1] = 20; // imag 변경

    std::cout << "c = " << c << std::endl; // 10 + 20i

    // (6) 증감, 단항 - 연산자 테스트
    ++c;
    std::cout << "++c = " << c << std::endl; 
    c--;
    std::cout << "c-- = " << c << std::endl;
    std::cout << "-c  = " << -c << std::endl;

    return 0;
}
