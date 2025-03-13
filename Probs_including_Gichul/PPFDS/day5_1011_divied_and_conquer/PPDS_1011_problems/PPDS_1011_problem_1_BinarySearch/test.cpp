#include <vector>
#include <iostream>

using namespace std;

int binarySearchHelper(const vector<int>& nums, int left, int right, int target) {
    /* Fill this function */
    if(left > right) return -1;
    int mid = (left+right)/2;
    cout <<" visit " << nums[mid] << " ";
    if(nums[mid]==target) return mid;
    else if(nums[mid]>target){
        return binarySearchHelper(nums,left,mid-1,target);
    }else{
        return binarySearchHelper(nums,mid+1,right,target);
    }
}

int binarySearch(const vector<int>& nums, int target) {
    int n = nums.size();
    return binarySearchHelper(nums,0,n-1,target);
}