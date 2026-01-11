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


/*
Example: nums = [10, 9, 2, 5, 3, 7, 101, 18]

Initial State:
nums   = [10, 9, 2, 5, 3, 7, 101, 18]
index  =   0  1  2  3  4  5   6   7
dp = [1, 1, 1, 1, 1, 1, 1, 1]
maxLength = 1

i = 6 (nums[6] = 101):
  j = 7: nums[7]=18, 18>101? ✗
  dp[6] stays 1
  maxLength = max(1, 1) = 1
  dp = [1, 1, 1, 1, 1, 1, 1, 1]

i = 5 (nums[5] = 7):
  j = 6: nums[6]=101, 101>7? ✓ → dp[5] = max(1+1, 1) = 2
  j = 7: nums[7]=18,  18>7?  ✓ → dp[5] = max(1+1, 2) = 2
  maxLength = max(1, 2) = 2
  dp = [1, 1, 1, 1, 1, 2, 1, 1]

i = 4 (nums[4] = 3):
  j = 5: nums[5]=7,   7>3?   ✓ → dp[4] = max(1+2, 1) = 3
  j = 6: nums[6]=101, 101>3? ✓ → dp[4] = max(1+1, 3) = 3
  j = 7: nums[7]=18,  18>3?  ✓ → dp[4] = max(1+1, 3) = 3
  maxLength = max(2, 3) = 3
  dp = [1, 1, 1, 1, 3, 2, 1, 1]

i = 3 (nums[3] = 5):
  j = 4: nums[4]=3,   3>5?   ✗
  j = 5: nums[5]=7,   7>5?   ✓ → dp[3] = max(1+2, 1) = 3
  j = 6: nums[6]=101, 101>5? ✓ → dp[3] = max(1+1, 3) = 3
  j = 7: nums[7]=18,  18>5?  ✓ → dp[3] = max(1+1, 3) = 3
  maxLength = max(3, 3) = 3
  dp = [1, 1, 1, 3, 3, 2, 1, 1]

i = 2 (nums[2] = 2):
  j = 3: nums[3]=5,   5>2?   ✓ → dp[2] = max(1+3, 1) = 4
  j = 4: nums[4]=3,   3>2?   ✓ → dp[2] = max(1+3, 4) = 4
  j = 5: nums[5]=7,   7>2?   ✓ → dp[2] = max(1+2, 4) = 4
  j = 6: nums[6]=101, 101>2? ✓ → dp[2] = max(1+1, 4) = 4
  j = 7: nums[7]=18,  18>2?  ✓ → dp[2] = max(1+1, 4) = 4
  maxLength = max(3, 4) = 4
  dp = [1, 1, 4, 3, 3, 2, 1, 1]

i = 1 (nums[1] = 9):
  j = 2-5: All nums[j] < 9, skip
  j = 6: nums[6]=101, 101>9? ✓ → dp[1] = max(1+1, 1) = 2
  j = 7: nums[7]=18,  18>9?  ✓ → dp[1] = max(1+1, 2) = 2
  maxLength = max(4, 2) = 4
  dp = [1, 2, 4, 3, 3, 2, 1, 1]

i = 0 (nums[0] = 10):
  j = 1-5: All nums[j] < 10, skip
  j = 6: nums[6]=101, 101>10? ✓ → dp[0] = max(1+1, 1) = 2
  j = 7: nums[7]=18,  18>10?  ✓ → dp[0] = max(1+1, 2) = 2
  maxLength = max(4, 2) = 4
  dp = [2, 2, 4, 3, 3, 2, 1, 1]

Final Result: maxLength = 4
dp[i] = length of longest increasing subsequence starting from index i
One valid LIS: [2, 5, 7, 101] (indices 2→3→5→6)

Time Complexity: O(n²)
Space Complexity: O(n)
*/