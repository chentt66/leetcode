from typing import List

# O(n) time
# O(1) space
class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        asteroids.sort()
        for i, m in enumerate(asteroids):
            if mass < m:
                return False
            mass += m
        return True