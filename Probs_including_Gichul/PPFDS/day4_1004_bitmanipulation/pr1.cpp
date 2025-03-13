#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> vec){
    // bit-wise로 풀라.. 잘 모르겠다.
    int result = 0;
    for(int x : vec){
        result ^= x;
    }
    return result;
/*
    int ans = -1;
    int n = vec.size();

    for(int i=0;i<n;i++){
        int cnt = 0;
        int temp = vec[i];
        for(int j=0;j<n;j++){
            if(temp==vec[j]) cnt++;
        }
        if(cnt%2 != 0){
            ans = temp;
            break;
        }
    }
    return ans;
*/
}

int main(){
    vector<int> vec = {9,3,9,3,9,7,9,7,8};
    cout << solution(vec) << endl;

    cout << (0b0 ^ 0b1001) << endl;
    cout << (0b1111 ^ 0b1001) << endl;
    cout << (0b1001 ^ 0b1001) << endl;

    return 0;
}