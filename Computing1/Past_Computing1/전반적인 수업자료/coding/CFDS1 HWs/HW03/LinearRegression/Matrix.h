#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/* Your code here */
class Matrix{
    public:
        vector< vector<double> > data;
        Matrix operator+ (const Matrix& M);
        Matrix operator- (const Matrix& M);
        Matrix operator* (const Matrix& M);
        Matrix Transpose ();
        Matrix GetSubVectorbyColumn(int column); // return a specific column as a n*1 matrix.
        void Print();
        int GetNumRow();
        int GetNumColumn();
        double GetVal(int x, int y);
};

class DataFrame{
    public:
        vector< vector<double> > rows;
        int ReadData(std::string FileName, char sep, char comment, bool IsHeader);
        Matrix GetMatrix(int index[], int nColumn);
};

Matrix Cor(Matrix&mat, int method=1);
Matrix SimpleLinearRegression(Matrix &X, Matrix &Y);

double Pearson(vector<double>& x, vector<double>& y);
double Kendall(vector<double>& x, vector<double>& y);
double average(vector<double>&x);
double covariance(vector<double>& x, vector<double>& y);