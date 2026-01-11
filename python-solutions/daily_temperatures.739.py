class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        deltas = [0] * n
        mstack = collections.deque([]) # mstack = []
        for i, t in enumerate(temperatures):
            while mstack and t > temperatures[mstack[-1]]:
                last_index = mstack[-1]
                deltas[last_index] = i - last_index
                mstack.pop()
            mstack.append(i)
        return deltas