#include <vector>
#include <algorithm>
using std::vector;
using std::max;

// e.g. nums = [100, 1, 1, 100]
// --> rob house 1 and house 4.

// O(n) time
// O(n) space -- easier to understand
// dp[i] 代表只考虑前 i+1 间房屋（即 nums[0..i]）时，能偷到的最大金额。 注意它不是"偷到第 i 间房"的金额，而是"在 0 到 i 这个范围内随便选、不偷相邻的，最优能拿多少"。所以 dp[i] 对应的方案里第 i 间房可能偷了，也可能没偷。
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

// O(n) time
// O(1) space: simialr to fibonacci
class Solution {
public:
    int rob(vector<int>& nums) {
        int dp_prev2 = 0;
        int dp_prev1 = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int val = max(nums[i] + dp_prev2, dp_prev1);
            dp_prev2 = dp_prev1;
            dp_prev1 = val;
        }
        return dp_prev1;  
    }
};