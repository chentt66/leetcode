# Optimized
# O(n) time
# O(1) space
class Solution:
    def maxArea(self, height: List[int]) -> int:
        left, right = 0, len(height) - 1
        max_area = 0
        while left < right:
            max_area = max(max_area, min(height[left], height[right]) * (right - left))
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return max_area

class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len(height) # n is only used once, omit it.
        left = 0
        right = n - 1
        max_area = 0
        while left < right:
            h = min(height[left], height[right]) # h is redundant
            width = right - left
            max_area = max(max_area, h * width)
            if h == height[left]:
                left += 1
            else:
                right -= 1
        return max_area
