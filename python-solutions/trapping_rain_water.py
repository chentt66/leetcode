# Water[i] = min(LeftMax, RightMax) - height[i]

# Two pointers (explicit)
# O(n) time
# O(1) space
class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        water = 0
        left = 0
        right = n - 1
        left_max = 0
        right_max = 0
        while left < right:
            left_max = max(height[left], left_max)
            right_max = max(height[right], right_max)
            if left_max < right_max:
                water += left_max - height[left]
                left += 1
            else:
                water += right_max - height[right]
                right -= 1
        return water

# Two pointers
# O(n) time
# O(1) space
class Solution:
    def trap(self, height: List[int]) -> int:
        water = 0
        n = len(height)
        left = 0
        right = n - 1
        left_max = 0
        right_max = 0
        while left < right:
            if height[left] < height[right]:
                left_max = max(height[left], left_max)
                water += left_max - height[left]
                left += 1
            else:
                right_max = max(height[right], right_max)
                water += right_max - height[right]
                right -= 1
        return water