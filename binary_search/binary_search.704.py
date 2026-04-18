# O(logn) time
# O(1) space
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        while left <= right:
            # must be =. Think about why.
            mid = (left + right) // 2 # no need for left + (right - left) / 2 -- prvent integer overlow in C++
            if nums[mid] == target: return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return -1
