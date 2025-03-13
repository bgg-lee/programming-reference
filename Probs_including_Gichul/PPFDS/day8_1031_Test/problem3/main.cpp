#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include "functions.hpp"

using namespace std;

vector<vector<int>> parseInput(const string& input) {
    vector<vector<int>> edges;
    string s = input;
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    if (s.front() == '[' && s.back() == ']') {
        s = s.substr(1, s.size() - 2);
    }
    stringstream ss(s);
    string edgeStr;
    while (getline(ss, edgeStr, ']')) {
        size_t pos = edgeStr.find('[');
        if (pos != string::npos) {
            edgeStr = edgeStr.substr(pos + 1);
        } else {
            continue;
        }
        stringstream edgeSS(edgeStr);
        string numStr;
        vector<int> edge;
        while (getline(edgeSS, numStr, ',')) {
            edge.push_back(stoi(numStr));
        }
        if (edge.size() == 2) {
            edges.push_back(edge);
        }
    }
    return edges;
}

// Test the solution
int main(int argc, char* argv[]) {

    vector<vector<int>> edges = parseInput(argv[1]);
    
    vector<int> result1 = function3(edges);
    cout << "[" << result1[0] << "," << result1[1] << "]" << endl;
    
    return 0;
}