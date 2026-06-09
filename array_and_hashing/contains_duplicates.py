# More like a simple brain teaser

# Hash set
# O(n) time
# O(n) space
class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        seen = set()
        for num in nums:
            if num in seen:
                return True
            seen.add(num)
        return False
    
# Hash set length
# O(n) time
# O(n) space
class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        return len(set(nums)) < len(nums)
    
# Sorting

# Brute force
