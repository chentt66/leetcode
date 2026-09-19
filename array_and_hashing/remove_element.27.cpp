class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int num : nums) {
            if (num != val) {
                nums[k++] = num;
                // nums[k] = num;
                // k += 1;
            }
        }
        return k;
    }s
};