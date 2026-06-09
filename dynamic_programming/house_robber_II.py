# 抢首、抢尾 —— 被新约束禁止,不可能出现
# 抢首、不抢尾
# 不抢首、抢尾
# 不抢首、不抢尾 e.g. nums = [1, 100, 1, 100, 1]


# pass low and high to optimize space
# O(n) time
# O(n) space
class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        def helper(low, high):
            val = dp_prev1 = dp_prev2 = 0
            for i in range(low, high):
                val = max(dp_prev2 + nums[i], dp_prev1)
                dp_prev2 = dp_prev1
                dp_prev1 = val
            return val
        return max(helper(0, n-1), helper(1, n))

class Solution:
    def rob(self, nums: list[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        def rob_linear(low: int, high: int) -> int:
            prev, curr = 0, 0  # prev = best two back, curr = best one back
            for i in range(low, high):
                prev, curr = curr, max(curr, prev + nums[i])
            return curr
        return max(rob_linear(0, n - 1), rob_linear(1, n))