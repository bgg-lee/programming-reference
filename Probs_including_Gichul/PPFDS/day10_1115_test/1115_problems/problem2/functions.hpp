#include <vector>
using namespace std;

// 일단 6/10

int function2(const std::vector<int>& arr) {
    // Fill this function
    int n = arr.size();
    
    // for문을 돌면서 작은놈 / 큰놈을 마주칠 때 스텐스가 달라진다.
    int ans = arr[0]; // 현재까지 max 누적 넓이
    int idx = 1; // 밑면의 넓이 tracking

    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            //작은 놈 마주침
            int temp1 = arr[i]*(++idx);
            ans = max(ans,temp1);
        }else{
            //크거나 같은 놈 마주침
            int temp2 = arr[i-1]*(idx+1);
            int temp3 = arr[i];
            int temp4;
            if(temp2<temp3){
                temp4 = temp3;
                idx=1;
            }
            else{
                temp4 = temp2;
                idx++;}
            ans = max(ans,temp4);
        }
        // cout << ans << " ";
    }

    

    return ans;
}

// If you need to construct another functions, write and use here. 
// However, you can not use those functions in main.cpp.
// Submit functions.hpp file.

// compile command: g++ -o main main.cpp
// execute command: 
//              ./main "2 1 5 6 2 3"
//              ./main "2 4"

// https://leetcode.com/problems/largest-rectangle-in-histogram/description/