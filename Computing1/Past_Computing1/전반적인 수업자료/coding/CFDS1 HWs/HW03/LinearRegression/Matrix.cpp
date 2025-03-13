#include "Matrix.h"

/* Your code here */
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

// 1.DataFrame
int DataFrame::ReadData(std::string FileName, char sep, char comment, bool IsHeader){
    ifstream myfile (FileName);
    string line;
    bool header_skip = true;
    if (myfile.is_open()){
        while (getline (myfile, line)){
            if (line[0] == comment){continue;}
            if (IsHeader && header_skip){header_skip = false; continue;}
            else{
            string tempStr;
            stringstream row(line);
            vector<double> tempVec;
            while (getline(row, tempStr, sep)){
                tempVec.push_back(stod(tempStr));
            }
            rows.push_back(tempVec);
            }
        }
    }
    else cout << "unable to open a file" << endl;
    return 0;
}
Matrix DataFrame::GetMatrix(int index[], int nColumn){
    Matrix mat;
    int rowsize = rows.size();
    for (int i = 0; i<rowsize; i++){
        vector<double> tempRow;
        for (int j=0; j<nColumn; j++){
            tempRow.push_back(rows[i][index[j]]);
        }
        // for (int i=0; i<tempRow.size(); i++){cout << tempRow[i] << ' ';} cout << endl;
        mat.data.push_back(tempRow);
    }

    return mat;
}

// 2. Matrix

Matrix Matrix::operator+(const Matrix& M){
    Matrix mat;
    int m = GetNumRow();
    int n = GetNumColumn();

    for (int i=0;i<m;i++){
        vector<double> tempRow;
        for (int j=0;j<n;j++){
            tempRow.push_back(data[i][j] + M.data[i][j]);
        }
        mat.data.push_back(tempRow);
    }
    return mat;
}
Matrix Matrix::operator-(const Matrix& M){
    Matrix mat;
    int m = GetNumRow();
    int n = GetNumColumn();

    for (int i=0;i<m;i++){
        vector<double> tempRow;
        for (int j=0;j<n;j++){
            tempRow.push_back(data[i][j] - M.data[i][j]);
        }
        mat.data.push_back(tempRow);
    }
    return mat;
}
Matrix Matrix::operator*(const Matrix& M){
    Matrix mat, newmat;
    int m = GetNumRow();
    int p = GetNumColumn();
    int n = M.data[0].size();
    cout << "sizeinfo" << m << ','<< p<< ','<< M.data.size()<<n <<endl;

    for (int i=0;i<m;i++){
        vector<double> tempRow;
        for (int j=0;j<n;j++){
            double elem = 0;
            for (int k=0; k<p; k++){
                elem += data[i][k] * M.data[k][j];
            }
            tempRow.push_back(elem);
        }
        newmat.data.push_back(tempRow);
    }
    return newmat;
}
Matrix Matrix::Transpose (){
    Matrix mat;
    int m = GetNumRow();
    int n = GetNumColumn();

    for (int j=0;j<n;j++){
        vector<double> tempRow;
        for (int i=0;i<m;i++){
            tempRow.push_back(data[i][j]);

        }
        mat.data.push_back(tempRow);
    }
    return mat;
}
Matrix Matrix::GetSubVectorbyColumn(int column){
    Matrix mat;
    int m = GetNumRow();
    int n = GetNumColumn();
    for (int i=0;i<m;i++){
        vector<double> tempRow;
        tempRow.push_back(data[i][column]);
        mat.data.push_back(tempRow);
    }
    return mat;
}
void Matrix::Print(){
    int m = GetNumRow();
    int n = GetNumColumn();
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            cout << data[i][j] << ' ';
        }
        cout << endl;
    }
}
int Matrix::GetNumRow(){return data.size();}
int Matrix::GetNumColumn(){return data[0].size();}
double Matrix::GetVal(int x, int y){return data[x][y];}

// 3. Implement other functions
Matrix Cor(Matrix&mat, int method){
    Matrix matT = mat.Transpose();
    Matrix newmat;
    int m = matT.GetNumRow();
    for (int i=0;i<m;i++){
        vector<double> tempRow;
        for (int j=0;j<m;j++){
            if (method==1) tempRow.push_back(Pearson(matT.data[i], matT.data[j]));
            else if (method==2) tempRow.push_back(Kendall(matT.data[i], matT.data[j]));
        }
        newmat.data.push_back(tempRow);
    }
    return newmat.Transpose();
}
Matrix SimpleLinearRegression(Matrix &X, Matrix &Y){
    double tangent, intercept;
    vector<double> x, y;
    for (int i=0; i<X.GetNumRow(); i++){
        x.push_back(X.data[i][0]);
        y.push_back(Y.data[i][0]);
    }
    tangent = covariance(x, y) / covariance(x, x);
    intercept = average(y) - tangent * average(x);

    Matrix LR;
    vector<double> Inter, Tan;
    Inter.push_back(intercept);
    Tan.push_back(tangent);
    LR.data.push_back(Inter);
    LR.data.push_back(Tan);
    return LR;
}

double Pearson(vector<double>& x, vector<double>& y){
    return covariance(x, y) / sqrt(covariance(x, x) * covariance(y, y));
}
double Kendall(vector<double>& x, vector<double>& y){
    int size = x.size();
    double concordant = 0, discordant = 0;
    double total_pair = size * (size-1) / 2;
    for (int i=0; i<size; i++){
        for (int j=0; j<i; j++){
            if ((x[i] - x[j]) * (y[i] - y[j]) >= 0) {concordant +=1;}
            else discordant +=1;
        }
    }
    return 1-2*discordant/total_pair;
}

double average(vector<double>& x){
    double sum = 0;
    for (double elem : x){
        sum += elem;
    }
    return sum / x.size();
}
double covariance(vector<double>& x, vector<double>& y){
    double mean_x = average(x);
    double mean_y = average(y);
    vector<double> xy;
    for (int i=0; i<x.size(); i++){
        xy.push_back(x[i] * y[i]);
    }
    return average(xy) - average(x) * average(y);
}