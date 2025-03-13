#include <vector>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
using namespace std;
#include <stack>

// int function2(const std::vector<int>& arr){
//     stack<int> s;
//     int maxArea = 0;
//     int n = arr.size();

//     for(int i=0; i<=n; i++){
//         int h = (i==n) ? 0 : arr[i]; //현재높이

//         while(!s.empty() && arr[s.top()] > h){
//             int height = arr[s.top()];
//             s.pop();
//             int width = s.empty() ? i : i - s.top() - 1;
//             maxArea = max(maxArea,height*width);
//         }
//         s.push(i);
//     }
//     return maxArea;
// }

#include <vector>
#include <iostream>
using namespace std;

int largestRectangleAreaDP(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n), right(n, n);

    // Calculate left limits
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        left[i] = s.empty() ? 0 : s.top() + 1;
        s.push(i);
    }

    // Clear the stack for right limits
    while (!s.empty()) s.pop();

    // Calculate right limits
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    // Calculate the maximum area
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i];
        maxArea = max(maxArea, heights[i] * width);
    }

    return maxArea;
}


int main() {
    vector<int> heights1 = {2, 1, 5, 6, 2, 3};
    vector<int> heights2 = {3, 4};

    cout << "Input: heights = [2,1,5,6,2,3]" << endl;
    cout << "Output: " << largestRectangleAreaDP(heights1) << endl; // Expected: 10
    cout << "Input: heights = [3,4]" << endl;
    cout << "Output: " << largestRectangleAreaDP(heights2) << endl; // Expected: 4

    // cout << "\nUsing DP Approach:" << endl;
    // cout << "Input: heights = [2,1,5,6,2,3]" << endl;
    // cout << "Output: " << function2(heights1) << endl; // Expected: 10
    // cout << "Input: heights = [2,4]" << endl;
    // cout << "Output: " << function2(heights2) << endl; // Expected: 4

    return 0;
}