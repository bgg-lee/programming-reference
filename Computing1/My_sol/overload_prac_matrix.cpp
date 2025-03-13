#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Matrix {
private:
    int rows, cols;
    vector<vector<T>> data;

public:
    // 1️⃣ 기본 생성자
    Matrix(int r, int c, T defaultValue = T()) : rows(r), cols(c), data(r, vector<T>(c, defaultValue)) {}

    // 2️⃣ `operator+` 오버로딩 (행렬 덧셈)
    Matrix<T> operator+(const Matrix<T>& other) const {
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    // 3️⃣ `operator-` 오버로딩 (행렬 뺄셈)
    Matrix<T> operator-(const Matrix<T>& other) const {
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result[i][j] = data[i][j] - other.data[i][j];
        return result;
    }

    // 4️⃣ `operator*` 오버로딩 (행렬 곱셈)
    Matrix<T> operator*(const Matrix<T>& other) const {
        Matrix<T> result(rows, other.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < other.cols; j++)
                for (int k = 0; k < cols; k++)
                    result[i][j] += data[i][k] * other.data[k][j];
        return result;
    }

    // 5️⃣ `operator[]` 오버로딩 (행 접근)
    vector<T>& operator[](int index) { return data[index]; }

    // 6️⃣ `operator=` 오버로딩 (대입 연산자)
    Matrix<T>& operator=(const Matrix<T>& other) {
        if (this == &other) return *this;
        rows = other.rows;
        cols = other.cols;
        data = other.data;
        return *this;
    }

    // 7️⃣ `operator==` 오버로딩 (행렬 비교)
    bool operator==(const Matrix<T>& other) const {
        return data == other.data;
    }

    // 8️⃣ `operator<<` 오버로딩 (출력)
    friend ostream& operator<<(ostream& os, const Matrix<T>& mat) {
        for (int i = 0; i < mat.rows; i++) {
            for (int j = 0; j < mat.cols; j++) {
                os << mat.data[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }

    // 9️⃣ `operator>>` 오버로딩 (입력)
    friend istream& operator>>(istream& is, Matrix<T>& mat) {
        for (int i = 0; i < mat.rows; i++)
            for (int j = 0; j < mat.cols; j++)
                is >> mat.data[i][j];
        return is;
    }
};

int main() {
    // ✅ 3x3 행렬 생성
    Matrix<int> A(3, 3, 1);
    Matrix<int> B(3, 3, 2);
    Matrix<int> C(3, 3);

    // ✅ 행렬 덧셈/뺄셈 테스트
    C = A + B;
    cout << "Matrix A + B:\n" << C << endl;

    C = A - B;
    cout << "Matrix A - B:\n" << C << endl;

    // ✅ 행렬 곱셈 테스트
    C = A * B;
    cout << "Matrix A * B:\n" << C << endl;

    // ✅ 대입 연산자 테스트
    Matrix<int> D = C;
    cout << "Matrix D (copied from C):\n" << D << endl;

    // ✅ 비교 연산자 테스트
    if (C == D) cout << "C and D are equal" << endl;

    // ✅ `operator[]` 테스트
    A[1][2] = 5;
    cout << "Modified A:\n" << A << endl;

    // ✅ 입력 연산 테스트
    Matrix<int> E(2, 2);
    cout << "Enter 2x2 matrix values: ";
    cin >> E;
    cout << "Entered Matrix:\n" << E << endl;

    return 0;
}
