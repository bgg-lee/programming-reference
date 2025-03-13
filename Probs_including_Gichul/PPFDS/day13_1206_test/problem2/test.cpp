# // Rod Cutting Probs


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
///help
int rodCutting(vector<int>& price, int n){

    if(n==0) return 0;

    int val = INT_MIN;
    for(int i=1; i<=n ; i++){

        val = max(val,price[i-1]+rodCutting(price,n-i));
        // val = price[i-1] + rodCutting(price,n-1);
    }

    return val;
}


int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = 8;

    cout << "Maximum obtainable value is " << rodCutting(price, n) << endl;

    return 0;
}