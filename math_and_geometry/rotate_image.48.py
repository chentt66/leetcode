
from typing import List

# O(n^2) time
# O(1) space: fully in-place.
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        # # transpose
        for i in range(n):
            for j in range(i): # 
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        # reverse by row
        for i in range(n):
            for j in range(n//2):
                matrix[i][j], matrix[i][n-1-j] = matrix[i][n-1-j], matrix[i][j]
        # OR:
        # for row in matrix:
        #     row.reverse()

        # OR:
        # for i in range(n):
        #     matrix[i][:] = matrix[i][::-1]



# Not in-place
import numpy as np
