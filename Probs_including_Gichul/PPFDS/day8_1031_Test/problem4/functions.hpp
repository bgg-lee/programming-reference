#include <vector>
using namespace std;

int function4(const std::vector<int>& arr) {
    // Fill this function
    int ans = 0;
    int left = 0;
    int right = arr.size()-1;
    int lv = 0;
    while (left < right) {
        int lower = arr[arr[left] < arr[right] ? left++ : right--];
        lv = max(lv, lower);
        ans += lv - lower;
        cout << "lv: " << lv <<", lower: "<<lower<<" ans: "<< ans << endl;
    }
    return ans;
}



// If you need to construct another functions, write and use here. 
// However, you can not use those functions in main.cpp.