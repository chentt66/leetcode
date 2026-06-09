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