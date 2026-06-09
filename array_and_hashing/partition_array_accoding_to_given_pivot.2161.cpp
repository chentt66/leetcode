class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        std::vector<int> result(n, pivot);
        int left = 0;
        int right = n - 1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < pivot) {
                result[left] = nums[i];
                left++;
            }
            if (nums[n-1-i] > pivot) {
                result[right] = nums[n-1-i];
                right--;
            }
        }
        return result;
    }
};