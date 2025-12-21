// Sliding window
// O(n) time
// O(1) space
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;
        int count = 1;
        for (int i = 1; i < 2*n; ++i) {
            if (nums[(i - 1) % n] <= nums[i % n]) {
                count++;
            } else {
                count = 1;
            }
            if (count == n) return true;
        }
        return false;
    }
};


// Brute force
// O(n^2) time
// O(1) space
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        for (int rotation = 0; rotation < n; ++rotation) {
            bool isSorted = true;
            for (int i = 0; i < n - 1; ++i) {
                int curr = nums[(i + rotation) % n];
                int next = nums[(i + rotation + 1) % n];
                if (curr > next) {
                    isSorted = false;
                    break;
                }
            }
            if (isSorted) return true;
        }
        return false;
    }
};