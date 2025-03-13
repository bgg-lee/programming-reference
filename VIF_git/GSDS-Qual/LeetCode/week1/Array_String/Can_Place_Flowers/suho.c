bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int count = 0;
    for(int i = 0; i < flowerbedSize; i++){
        if(i==0 && flowerbed[i]==0 && flowerbed[i+1]==0){
            flowerbed[i] = 1;
            count++;
        }
        else if(i==flowerbedSize-1 && flowerbed[i]==0 && flowerbed[i-1]==0){
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
