class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_can = *max_element(candies.begin(), candies.end());
        vector<bool> res(candies.size());
        for(int i = 0; i<candies.size(); i++){
            res[i] = candies[i]+extraCandies >= max_can;
        } 

        return res;
    }
};
