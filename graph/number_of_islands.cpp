// BFS
// use some modern C++ features
// O(m*n) time
// O(min(m,n)) space
class Solution {
private:
    // Use static to avoid re-allocation on stack every call
    // array for 4 adjacent directions: left, right, up, down
    static constexpr int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int m, n;

    void bfs(std::vector<vector<char>>& grid, int i, int j) {
        std::queue<std::pair<int, int>> q; // queue to visit cells in BFS
        q.push({i,j});
        grid[i][j] = '#'; // must mark the starting cell as visited to prevent revisiting
        
        while (!q.empty()) {
            auto [x, y] = q.front(); // structured binding, ok since C++ 17
            q.pop();
            // check 4 directions
            for (const auto& direction : directions) {
                // previous method: for (auto direction : directions) is a copy
                int adjx = x + direction[0];
                int adjy = y + direction[1];
                // check boundaries and whether the cell represent a land('1')
                if (adjx >= 0 && adjx < m
                    && adjy >= 0 && adjy < n
                    && grid[adjx][adjy] == '1'
                ) {
                    grid[adjx][adjy] = '#'; // mark as visited
                    q.push({adjx, adjy});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        // number of rows and columns
        m = grid.size();
        n = grid[0].size();
        int islands = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++islands;
                    bfs(grid, i, j);
                }
            }
        }
        return islands;
        
    }
};