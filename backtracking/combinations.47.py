class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        cnk = []
        def backtrack(current, start):
            if len(current) == k:
                cnk.append(current[:])
                return # still works without early return
            for i in range(start, n+1):
                current.append(i)
                backtrack(current, i+1)
                current.pop()
        backtrack(current=[], start=1)
        return cnk