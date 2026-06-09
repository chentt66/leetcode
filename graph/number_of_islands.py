from typing import List

# ====================== DFS  ====================== #
# mark visited in-place
# O(m*n) time
# O(m*n) space: entirely from recursion call stack
    # In the worst case, the entire grid is land ('1') arranged so that the DFS traverses it as one long non-branching path — for example a snake-like shape where each cell leads to exactly one unvisited neighbor.
class Solution:
    def numIslands(self, grid: List[str]) -> int:
        m, n = len(grid), len(grid[0])
        def dfs(x: int, y: int) -> None:
            if not (0 <= x < m and 0 <= y < n) or grid[x][y] != '1':
                return
            grid[x][y] = '#'
            dfs(x + 1, y)
            dfs(x - 1, y)
            dfs(x, y + 1)
            dfs(x, y - 1)
        islands = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    islands += 1
                    dfs(i, j)
        return islands

# mark visited in-place
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        islands = 0
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        def dfs(x, y):
            grid[x][y] = '#'
            for (dx, dy) in directions:
                adjx = x + dx
                adjy = y + dy
                if (0 <= adjx < m) and (0 <= adjy < n) and (grid[adjx][adjy] == '1'):
                    dfs(adjx, adjy)
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    islands += 1
                    dfs(i, j)
        return islands

# use hash set to mark visited
# adds another O(m*n) for the set (not recommended)
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        islands = 0
        visited = set()
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        def dfs(x, y):
            visited.add((x, y))
            for (dx, dy) in directions:
                adjx = x + dx
                adjy = y + dy
                if (0 <= adjx < m) and (0 <= adjy < n) and (grid[adjx][adjy] == '1') and ((adjx, adjy) not in visited):
                    dfs(adjx, adjy)
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1' and (i, j) not in visited:
                    islands += 1
                    dfs(i, j)
        return islands



# ====================== BFS  ====================== #
# O(m*n) time
# O(min(m*n)) space: why?
from collections import deque
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        islands = 0
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        def bfs(i, j):
            grid[i][j] = '#' 
            q = deque([])
            q.append((i, j))
            while q:
                x, y = q.popleft()
                for (dx, dy) in directions:
                    adjx = x + dx
                    adjy = y + dy
                    if (0 <= adjx < m) and (0 <= adjy < n) and (grid[adjx][adjy] == '1'):
                        grid[adjx][adjy] = '#'
                        q.append((adjx, adjy))

        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    islands += 1
                    bfs(i, j)
        return islands