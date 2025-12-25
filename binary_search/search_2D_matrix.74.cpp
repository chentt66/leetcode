// 1D to 2D
// row = index / n
// col = index % n

// 2D to 1D
// index = row * n + col

// O(log(m+n)) time
// O(1) space
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (m == 0 || n == 0) return false;
        // squeeze
        int left = 0;
        int right = m * n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int r = mid / n;
            int c = mid % n;
            if (matrix[r][c] == target) return true;
            if (matrix[r][c] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};