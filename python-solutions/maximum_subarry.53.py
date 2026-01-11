class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if not nums:
            return 0
        dp = nums # copy
        n = len(nums)
        max_sum = dp[0]
        for i in range(1, n):
            dp[i] = max(dp[i], dp[i-1]+nums[i])
            max_sum = max(dp[i], max_sum)
        return max_sum