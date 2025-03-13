#include "prob3_b.hpp"
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

class LogisticRegression {
public:
    void fit(const vector<vector<double>>& X_train, const vector<int>& y_train, double lr, int epochs);
    vector<int> predict(const vector<vector<double>>& X_test);
private:
    vector<double> weights;
    double sigmoid(double z);
    double dotProduct(const vector<double>& a, const vector<double>& b);
};

