// O(log n) time complexity
// fill later...



// O(n) time complexity
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                int start = mid;
                int end = mid;
                while (start >= 0 && nums[start] == target) {
                    start--;
                }
                while (end <= nums.size()-1 && nums[end] == target) {
                    end++;
                }
                return std::vector<int> {start+1, end-1};
            }
            if (nums[mid] < target) {
                left = mid + 1;
            }
            if (nums[mid] > target) {
                right = mid - 1;
            }
    }
        return std::vector<int> {-1, -1};
    }
};