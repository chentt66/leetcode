# O(n*2^n) time
# O(n*2^n) space

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        s = [] # size: 2^n
        def backtrack(current, start):
            s.append(current[:])
            for i in range(start, n):
                current.append(nums[i])
                backtrack(current, i+1)
                current.pop()
            return
        backtrack([], 0)
        return s