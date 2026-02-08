class Solution:
    def maxArea(self, height: List[int]) -> int:
        max_area = 0
        left = 0
        right = len(height) - 1
        while left < right:
            width = right - left
            max_area = max(max_area, width * min(height[left], height[right]))
            if height[left] <= height[right]:
                # left bar is shorter, so move one step to right. If the next bar is higher, the new area MAY(!) become larger.
                left += 1
            elif height[left] > height[right]:
                right -= 1
        return max_area
# Note:
# O(n^2) brute force: max_{i,j} { (j-i) * min(h[i], h[j]) }
# j-i will certainly become smaller in the loop, but min(h[i], h[j]) will not.

# When widthn becomes smaller, I need a higher height to offset: move the index of the shorter bar one step towards the middle. If the new bar is higher than the previous shorter bar, the new area MAY become larger.
# There is always a trade-off between (longer width * current height) and (sure shorter width * potential higher height )

class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len(height)
        left = 0
        right = n - 1
        water = 0
        max_water = 0
        while left < right:
            width = right - left
            if height[left] < height[right]:
                water = height[left] * width
                # move the pointer
                left += 1
            else:
                water = height[right] * width
                right -= 1
            max_water = max(max_water, water)
        return max_water