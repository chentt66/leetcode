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
                if num not in curr:
                    curr.append(num)
                    backtrack(curr)
                    curr.pop()

        backtrack(curr=[])
        return permutations