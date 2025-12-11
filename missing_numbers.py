# Sort
# O(N*logN) time
# O(1) space
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        if nums[0] != 0: return 0
        if nums[n - 1] != n: return n
        for i in range(1, len(nums)):
            if nums[i] - nums[i-1] > 1:
                return i

# Brute force
# O(n^2) time
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(0, n + 1):
            if i not in nums:
                return i