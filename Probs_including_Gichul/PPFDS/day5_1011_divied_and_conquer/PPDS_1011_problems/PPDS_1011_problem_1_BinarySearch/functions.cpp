#include <vector>
#include <iostream>

using namespace std;

int binarySearchHelper(const vector<int>& nums, int left, int right, int target) {
    /* Fill this function */
    if(left>right) return -1;

    int mid = (left+right)/2;
    cout << nums[mid] << " ";
    if(nums[mid]==target) return mid;
    else if(nums[mid]<target) return binarySearchHelper(nums,mid+1,right,target);
    else return binarySearchHelper(nums,left,mid-1,target);
}

int binarySearch(const vector<int>& nums, int target) {
    return binarySearchHelper(nums, 0, nums.size() - 1, target);
}