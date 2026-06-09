# My solution: Two pointers
# O(n) time
# O(1) space
class Solution:
    def trap(self, height: List[int]) -> int:
        water = 0
        left = left_max = 0
        right = right_max = len(height) - 1
        while left < right:
            if height[left] < height[right]:
                if height[left] < height[left_max]:
                    water += height[left_max] - height[left]
                else:
                    left_max = left
                left += 1
            else:
                if height[right] < height[right_max]:
                    water += height[right_max] - height[right]
                else:
                    right_max = right
                right -= 1
        return water


# Two pointers
# O(n) time
# O(1) space
class Solution:
    def trap(self, height: List[int]) -> int:
        water = 0
        left = 0
        right = len(height) - 1
        h_left_max = h_right_max = 0
        while left < right:
            h_left_max = max(height[left], h_left_max)
            h_right_max = max(height[right], h_right_max)
            if h_left_max < h_right_max:
                water += h_left_max - height[left]
                left += 1
            else:
                water += h_right_max - height[right]
                right -= 1
        return water