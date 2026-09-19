# optimized solution
class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        result = []
        candidates.sort() # sort once to save time?
        n = len(candidates)
        def backtrack(current, rest, start):
            if rest == 0:
                result.append(current[:])
                return
            for i in range(start, n):
                if candidates[i] <= rest:
                    current.append(candidates[i])
                    backtrack(current, rest - candidates[i], i)
                    current.pop()
        backtrack([], target, 0)
        return result



# first solution
class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        result = []
        def backtrack(current, next_target):
            if next_target == 0:
                current = sorted(current)
                if current not in result:
                    result.append(current[:])
                return
            for num in candidates:
                if num <= next_target:
                    current.append(num)
                    backtrack(current, next_target-num)
                    current.pop()
        backtrack([], target)
        return result