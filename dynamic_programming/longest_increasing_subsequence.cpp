// For each element, there are two choices:
// (1) Include it in the subsequence.
// (2) Exclude it from the subsequence.
// --> 2^n choices

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 1;
        std::vector<int> dp(n, 1);
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] > nums[i]) {
                    dp[i] = max(1 + dp[j], dp[i]);
                }
            }
            maxLength = max(maxLength, dp[i]);
        }
        return maxLength;
    }
};

// O(n^2) time
// O(n) space
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> dp(n, 1);
        int maxLength = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLength = max(maxLength, dp[i]);
        }
        return maxLength;
    }
};