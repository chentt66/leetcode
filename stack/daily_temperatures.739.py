from typing import List

# my solution
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        deltas = [0] * len(temperatures)
        st = []
        for i, temp in enumerate(temperatures):
            while st:
                top_j = st[-1]
                if temp > temperatures[top_j]:
                    deltas[top_j] = i - top_j
                    st.pop()
                else:
                    break
            st.append(i)
        return deltas

# Monotonic stack
# Time: O(n). Each index is pushed and popped at most once (amortized analysis).
# Space: O(n). Auxiliary space for the monotonic stack, which in the worst case (strictly decreasing input) holds all n indices.
# 单调栈问题标准模板？ while stack and 条件: pop
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        deltas = [0] * len(temperatures)
        mstack = []
        for i, temp in enumerate(temperatures):
            while mstack and temp > temperatures[mstack[-1]]:
                top_j = mstack.pop()
                deltas[top_j] = i - top_j
            mstack.append(i)
        return deltas