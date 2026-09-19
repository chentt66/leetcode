class Solution:
    def maxProduct(self, nums: list[int]) -> int:
        global_max_prod = nums[0]
        max_prod = nums[0]  # local max/min including the the current num
        min_prod = nums[0]
        for num in nums[1:]:
            if num < 0:
                max_prod, min_prod = min_prod, max_prod
            max_prod = max(max_prod * num, num)
            min_prod = min(min_prod * num, num)
            global_max_prod = max(global_max_prod, max_prod)
        return global_max_prod

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