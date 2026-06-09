
# Backtracking (optimal)
# O(m*n*4^L) time
# O(L) space: 递归栈深度等于单词长度
class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        m, n = len(board), len(board[0])
        l = len(word)
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        def dfs(x, y, loc):
            if loc == l:
                return True
            if not (0 <= x < m and 0 <= y < n):
                return False
            if board[x][y] != word[loc]:
                return False
            char = board[x][y]
            board[x][y] = '#'
            found = dfs(x-1, y, loc+1) or dfs(x+1, y, loc+1) or dfs(x, y-1, loc+1) or dfs(x, y+1, loc+1)
            board[x][y] = char
            return found
    
        for i in range(m):
            for j in range(n):
                    if dfs(i, j, 0):
                        return True
        return False


# My first solution (not uniform...)
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        l = len(word)
        m, n = len(board), len(board[0])
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        def dfs(i, j, target):
            if target == l:
                return True
            board[i][j] = '#'
            for d in directions:
                adjx, adjy = i+d[0], j+d[1]
                if (0<=adjx<m) and (0<=adjy<n) and (board[adjx][adjy]==word[target]):
                    if dfs(adjx, adjy, target+1):
                        return True
            board[i][j] = word[target-1] # 当这个递归分支结束后必须把 board[i][j] 还原，因为其他路径可能合法地经过这个格子
            return False
        for i in range(m):
            for j in range(n):
                if board[i][j] == word[0]:
                    if dfs(i, j, 1):
                        return True
        return False
    