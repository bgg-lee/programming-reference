class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for(int i = 0; i < flowerbed.size(); i++){
            if(i==0 && flowerbed[i]==0 && flowerbed[i+1]==0){
                flowerbed[i] = 1;
                count++;
            }
            else if(i==flowerbed.size()-1 && flowerbed[i]==0 && flowerbed[i-1]==0){
                flowerbed[i] = 1;
                count++;
            }
            else if(flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0){
                flowerbed[i] = 1;
                count++;
            }
            if(count >= n) break;
        }

        return count >= n;
    }
};
