# Optimize space
# O(n) time
# O(1) space 
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if not nums:
            raise ValueError("Input must be non-empty")
        max_sum = nums[0] # global maximum of contiguous sum
        best_ending_sum = nums[0] # best subarray sum ending at the current position i / the maximum subarray sum that must end at index i
        for i in range(1, len(nums)):
            if best_ending_sum > 0:
                best_ending_sum += nums[i]
            else:
                best_ending_sum = nums[i]
            max_sum = max(max_sum, best_ending_sum)
        return max_sum