# Notice F(0) = 0, F(1) = 1. What is the first index/first fibonnaci number?
# O(n) time
# O(1) space
class Solution:
    def fib(self, n: int) -> int:
        # invalid cases: n < 0
        if n <= 1: return n
        a = 0
        b = 1
#         i = 1
#         while i < n:
#             f = a + b
#             a = b
#             b = f
#             i += 1
        for i in range(1, n):
            f = a + b
            a = b
            b = f
        return f
