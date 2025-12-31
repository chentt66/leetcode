// O(n) time
// O(1) space: same idea as fibonacci
class Solution {
public:
    int rob(vector<int>& nums) {
        int dpPrev2 = 0;
        int dpPrev1 = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int val = max(nums[i] + dpPrev2, dpPrev1);
            dpPrev2 = dpPrev1;
            dpPrev1 = val;
        }
        return dpPrev1;  
    }
};
// e.g nums = [100, 1, 1, 100]
// --> rob house 1 and house 4.

// O(n) time
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