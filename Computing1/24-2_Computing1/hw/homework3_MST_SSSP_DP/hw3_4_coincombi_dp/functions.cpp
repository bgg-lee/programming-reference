#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // 내가 추가

#include "functions.hpp"

using namespace std;
// backtrack 내 풀이
// void backtrack(long& cnt,int start, int target, vector<int>& candidates){
//     if(target==0){
//         cnt++;
//         return;
//     }else if(target<0) return;
    
//     for(int i = start;i<candidates.size();i++){
//         backtrack(cnt,start,target-candidates[i],candidates);
//     }

// }
// long coinCombinations(int n, int sum, vector<int> & coins)
// {
//     long ans = 0;
//     backtrack(ans,0,sum,coins);

//     return ans % INT_MAX;
// }

//만약 중복이 허용 안 된다-> [2,2,3] = [2,3,2] = [3,2,2]
// void backtrack(long& ans,int start,int target,vector<int>& vec,const vector<int> & coins){
//     if(target==0){
//         ans++;
//         return;
//     }else if(target<0) return;
//     for(int i=start;i<coins.size();i++){
//         vec.push_back(coins[i]);
//         backtrack(ans,i,target-coins[i],vec,coins);
//         vec.pop_back();
//     }

// }


// long coinCombinations(int n, int sum, vector<int> & coins)
// {
//     vector<int> vec = {};
//     long ans = 0;
//     backtrack(ans,0,sum,vec,coins);
//     return ans % INT_MAX;
// }



// DP 풀이
// long coinCombinations(int n, int sum, vector<int> &coins) {
//     vector<long> dp(sum + 1, 0);
//     dp[0] = 1;  // 0원을 만들 수 있는 방법은 1가지 (아무것도 선택 안 하는 경우)

//     // 코인을 사용하여 조합 만들기 (순서가 중요하므로 sum 먼저)
//     for (int x = 1; x <= sum; x++) {
//         for (int coin : coins) {
//             if (x >= coin) {
//                 dp[x] = (dp[x] + dp[x - coin]) % INT_MAX;  // MOD 연산 적용
//             }
//         }
//     }
    
//     return dp[sum];
// }


// #include <stack>
// #include <tuple>
// long coinCombinations(int n, int sum, vector<int> & coins)
// {
//     long ans = 0;
//     stack< tuple<int,int,vector<int>> > s;
//     s.push({0,0,{}});

//     while(!s.empty()){ // 사실 lst는 없어도 된다. 혹시 가능한 모든 조합을 vector로 보여달라 할까봐 넣은것
//         auto [idx, result, lst] = s.top();
//         s.pop();
//         if(result==sum) ans++; // 여기서 답 vector에 push_back 때리면 가능한 모든 vector조합 보여주기 가능
//         else if(result > sum) continue;
//         else{
//             for(int i=idx;i<n;i++){
//                 vector<int> temp;
//                 temp.push_back(coins[i]);
//                 s.push({i,result+coins[i],temp}); // 여기서 i->중복제거, i가 아니고 idx넣으면 중복허용한 comb sum 추적가능!
//             }   
//         }
//     }
    
//     return ans % INT_MAX;
// }


//내가 다시 DP 풀이 dynamic programming
long coinCombinations(int n, int sum, vector<int> & coins){
    
    vector<long> dp(sum+1,0);
    dp[0] = 1;
    
    for(int i=0;i<=sum;i++){
        for(const int coin : coins){
            if(i>=coin){
                dp[i] += dp[i-coin];
            }
        }
    }
    return dp[sum] % INT_MAX;
}   