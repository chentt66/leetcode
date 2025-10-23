class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (target == nums[mid]) return mid;
            if (nums[mid] < target) {
                // search the right half
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
