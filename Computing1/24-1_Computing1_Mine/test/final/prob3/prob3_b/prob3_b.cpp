#include "prob3_b.hpp"
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void LogisticRegression::fit(const vector<vector<double>>& X_train, const vector<int>& y_train, double initial_lr, int epochs) {
    int m = X_train.size();
    int n = X_train[0].size();
    weights = vector<double>(n, 0.0);

    // implement the fit function here
    // use sigmoid and dotProduct functions

}

vector<int> LogisticRegression::predict(const vector<vector<double>>& X_test) {
    vector<int> predictions(X_test.size());

    // implement the predict function. threshold = 0.5

    return predictions;
}

double LogisticRegression::sigmoid(double z) {
    return 0.0; // change the return value. hint: exp()
}

double LogisticRegression::dotProduct(const vector<double>& a, const vector<double>& b) {
    double result = 0.0;

    // implement 

    return result;
}
