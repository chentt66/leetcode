class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        if (nums.empty()) return nums;
        std::vector<int> s(2*n); // size is exactly 2n?
        // not in place
        for (int i = 0; i < n; ++i) {
            s[2*i] = nums[i]; // not striaghtforward at the first glance...
            s[2*i + 1] = nums[n + i];
        }
        return s;
    }
};