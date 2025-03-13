#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>

#include "prob3_b.hpp"

using namespace std;

// Function to read CSV file
vector<vector<double>> readCSV(const string& file) {
    ifstream in(file);
    if (!in.is_open()) {
        throw runtime_error("Could not open file: " + file);
    }
    
    string line;
    string cell;
    vector<vector<double>> data;
    // Skip the header line
    if (!getline(in, line)) {
        throw runtime_error("File is empty or cannot read header: " + file);
    }
    
    while (getline(in, line)) {
        stringstream lineStream(line);
        vector<double> row;
        while (getline(lineStream, cell, ',')) {
            try {
                row.push_back(stod(cell));
            } catch (const invalid_argument& e) {
                cerr << "Invalid number found in CSV file: " << cell << endl;
                throw;  // Throw the exception to be handled by the caller
            }
        }
        // Check for empty lines
        if (!row.empty()) {
            data.push_back(row);
        }
    }
    return data;
}

int main() {
    // Load the dataset
    vector<vector<double>> data = readCSV("train_val_data.csv");
    vector<vector<double>> X(data.size(), vector<double>(4));
    vector<int> y(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        X[i][0] = data[i][0];
        X[i][1] = data[i][1];
        X[i][2] = data[i][2];
        X[i][3] = data[i][3];
        y[i] = data[i][4];
    }
    // Split data into training (90%), validation (10%)
    int train_size = static_cast<int>(0.9 * X.size());
    int val_size = static_cast<int>(0.1 * X.size());
    vector<vector<double>> X_train(X.begin(), X.begin() + train_size);
    vector<vector<double>> X_val(X.begin() + train_size, X.begin() + train_size + val_size);
    vector<int> y_train(y.begin(), y.begin() + train_size);
    vector<int> y_val(y.begin() + train_size, y.begin() + train_size + val_size);

    // Logistic Regression with SGD
    LogisticRegression model;
    model.fit(X_train, y_train, 0.01, 100);
    vector<int> y_pred_val = model.predict(X_val);

    // Check the learning rate
    cout << model.lr;

    // Expected Output: 5.44812e-18

    return 0;
}
