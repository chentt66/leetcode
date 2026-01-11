class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        islands = 0
        if not grid or not grid[0]:
            return islands
        m = len(grid)
        n = len(grid[0]) # len(grid[0]) will throw IndexError if grid is empty, so we must check it before.
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    islands += 1
                    self.bfs(grid, i, j, m, n)
        return islands
    
    def bfs(self, grid, i, j, m, n):
        grid[i][j] = '0' # mark visited
        q = collections.deque([])
        q.append([i, j])
        directions = [[-1, 0], [1, 0],
                      [0, -1], [0, 1]]
        while q:
            x = q[0][0]
            y = q[0][1]
            q.popleft()
            for d in directions:
                adjx = x + d[0]
                adjy = y + d[1]
                if (0 <= adjx < m) and (0 <= adjy < n) and (grid[adjx][adjy] == '1'):
                    grid[adjx][adjy] = '0'
                    q.append([adjx, adjy])