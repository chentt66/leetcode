// Given an integer array nums, 
// find the subarray with the largest sum, and return its sum.
#include <iostream>
#include <algorithm>

// Kadane's algorithm
// O(n) time
// O(1) space
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0]; // global best sum
        int current_max = nums[0]; // best sum of a subarray ending at current index
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            // extend the previous subarray, or start a new one at nums[i]
            current_max = std::max(nums[i] + current_max, nums[i]);
            max_sum = std::max(max_sum, current_max);
        }
        return max_sum;
    }
};

// O(n) time
// O(n) space: for a more nuanced undertsanding of dp[i] in this problem
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        std::vector<int> dp = nums; // must copy nums
        int maxSum = dp[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = max(dp[i-1] + nums[i], dp[i]);
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;  // *std::max_element(dp.begin(), dp.end());
    }
};