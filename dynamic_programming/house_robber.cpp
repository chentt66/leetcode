// O(n) time
// O(1) space
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // [robPrev2, rob1Prev1, nums[n], nums[n+1] ...]
        int robPrev2 = 0;
        int robPrev1 = 0;
        for (int num : nums) {
            int dp = max(robPrev2 + num, robPrev1);
            robPrev2 = robPrev1;
            robPrev1 = dp;
        }
        return robPrev1;
    }
};
// e.g nums = [100, 1, 1, 100]
// --> rob house 1 and house 4.


// O(n) space: easier to understand
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        std::vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[n - 1];
        
    }
};