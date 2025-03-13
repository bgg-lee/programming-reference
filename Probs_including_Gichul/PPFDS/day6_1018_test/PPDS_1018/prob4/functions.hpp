#include <vector>

using namespace std;

int reversePairs(vector<int>& nums) {
    // Fill this function
    int ans = 0;
    int n = nums.size();

    for(int i=0;i<n;i++){
        int temp = nums[i];
        for(int j=i+1;j<n;j++){
            if(temp > 2*nums[j]) ans++;
        }
    }

    return ans;
}

// If you need to construct another functions, write and use here. 
// However, you can not use those functions in main.cpp.
