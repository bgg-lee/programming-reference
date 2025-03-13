#include <iostream>
#include <vector>
using namespace std;

int Sol(const vector<int> &vec){
    int ans = INT_MAX;
    int n = vec.size();
    for(int j=0;j<n;j++){
        int temp = vec[j];
        for(int i=j+1;i<n;i++){
            // if(i==j) continue;
            ans = min(ans,temp^vec[i]);
        }
    }
    // combination을 짤 수가 있나?

    return ans;
}

int main(){
    vector<int> vec1 = {0,2,5,7};
    vector<int> vec2 = {12,15,7,9};
    cout << Sol(vec1) << endl;
    cout << Sol(vec2) << endl;
    cout <<(3^8^7^3^8); // XOR에는 교환법칙이 성립한다.
    // XOR은 두 숫자가 비슷?해야 숫자가 작아지니까 sort하고 계산하면 계산 빨라질수도?
}
// 0111
// 1001
// 1110
