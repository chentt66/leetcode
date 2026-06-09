class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        current_max = nums[0] # local max/min including the the current num
        current_min = nums[0]
        max_prod = nums[0]
        for i in range(1, len(nums)):
            num = nums[i]
            if num < 0:
                current_max, current_min = current_min, current_max
            current_max = max(current_max * num, num)
            current_min = min(current_min * num, num)
            max_prod = max(max_prod, current_max)
        return max_prod

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        max_prod = nums.copy()
        min_prod = nums.copy()
        best = nums[0]
        for i in range(1, n):
            if nums[i] < 0:
                max_prod, min_prod = min_prod, max_prod
            max_prod[i] = max(max_prod[i-1] * nums[i], nums[i])
            min_prod[i] = min(min_prod[i-1] * nums[i], nums[i])
            best = max(best, max_prod[i])
        return best