class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k = k % len(nums) # important!!!
        n = len(nums)
        self.reverse_helper(nums, 0, n - 1)
        # or: nums[:] = nums[::-1]
        # or: nums.reverse()
        self.reverse_helper(nums, 0, k - 1)
        self.reverse_helper(nums, k, n - 1)

    def reverse_helper(self, nums, left, right) -> None:
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1
