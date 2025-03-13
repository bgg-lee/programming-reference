// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0, left = 0, right = height.size() - 1, level = 0;
        while (left < right) {
            int lower = height[height[left] < height[right] ? left++ : right--];
            level = max(level, lower);
            result += level - lower;
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        int i = 0, j = height.size() - 1;
        int left_height = height[0];
        int right_height = height[height.size() - 1];
        int trap = 0;

        while (i < j) {
            if (left_height < right_height) {
                ++i;
                // Fill in the gap.
                trap += max(0, left_height - height[i]);
                // Update current max height from left.
                left_height = max(left_height, height[i]);
            }
            else {
                --j;
                // Fill in the gap.
                trap += max(0, right_height - height[j]);
                // Update current max height from right.
                right_height = max(right_height, height[j]);
            }
        }

        return trap;
    }
};

//dp sol
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         if(height.empty()) return 0;

//         int n = height.size();

//         // Make DP
//         vector<int> left_max(n,0);
//         vector<int> right_max(n,0);
        
//         // Calculate Left max
//         left_max[0] = height[0];
//         for(int i=1;i<n;i++){
//             left_max[i] = max(left_max[i-1],height[i]);
//         }
//         // Calculate Right max
//         right_max[n-1] = height[n-1];
//         for(int j=n-2;j>=0;j--){
//             right_max[j] = max(right_max[j+1],height[j]);
//         }

//         // Calculate answer
//         int trap = 0;
//         for(int k=0;k<n;k++){
//             trap += (min(left_max[k],right_max[k])-height[k]);
//         }
//         return trap;
//     }
// };