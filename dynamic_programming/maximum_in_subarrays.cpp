// Given an integer array nums, find the subarray with the largest sum, and return its sum.


// Kadane's algorithm
// O(n) time
// O(n) space
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        std::vector<int> dp = nums; // must copy nums
        int maxSum = dp[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1] + nums[i], dp[i]);
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
        
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        std::vector<int> dp = nums;
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1] + nums[i], dp[i]);
        }
        return *std::max_element(dp.begin(), dp.end());
    }
};
