class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        permutations = []
        n = len(nums)
        def backtrack(start):
            if start == n:
                permutations.append(nums[:])
                return
            for i in range(start, n):
                # Swap to place nums[i] at the current 'start' position
                nums[start], nums[i] = nums[i], nums[start]
                backtrack(start + 1)
                # Swap back to restore the original state
                nums[start], nums[i] = nums[i], nums[start]
        backtrack(0)
        return permutations
    

# O(n*n!) time
# O(n*n!) space
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        permutations = []
        n = len(nums)
        def backtrack(curr):
            if len(curr) == n:
                permutations.append(curr[:])
            for num in nums:
                if num not in curr: # bottle neck
                    curr.append(num)
                    backtrack(curr)
                    curr.pop()

        backtrack(curr=[])
        return permutations


import itertools
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        return [list(p) for p in itertools.permutations(nums)]