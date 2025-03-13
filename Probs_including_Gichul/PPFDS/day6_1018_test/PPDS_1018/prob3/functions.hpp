
#include <vector>

using namespace std;

int getInvCount(vector<int> &arr) {
    // Fill this function
    int ans = 0;
    int n = arr.size();

    for(int i=0;i<n;i++){
        int temp = arr[i];
        for(int j=i+1;j<n;j++){
            if(arr[j]<temp) ans++;
        }
    }
    return ans;
} ;

// If you need to construct another functions, write and use here. 
// However, you can not use those functions in main.cpp.
