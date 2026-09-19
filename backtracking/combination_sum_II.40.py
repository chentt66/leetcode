
class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        result = []
        candidates.sort()
        n = len(candidates)
        def backtrack(current, rest, start):
            if rest == 0:
                result.append(current[:])
                return
            for i in range(start, n):
                if candidates[i] > rest:
                    return
                if i > start and candidates[i] == candidates[i-1]:
                    continue
                current.append(candidates[i])
                backtrack(current, rest - candidates[i], i + 1)
                current.pop()
        backtrack([], target, 0)
        return result