class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        if (nums.empty()) return {};
        int n = nums.size();
        std::vector<int> result(2*n); // pre-allocate space for 2*n elements, otherwise use push back
        for (int i = 0; i < n; ++i) {
            result[i] = nums[i];
            result[i + n] = nums[i];
        }
        // for (int i = 0; i < n; ++i) {
        //     result[i] = nums[i];
        // }
        // for (int i = n; i < 2*n; ++i) {
        //     result[i] = nums[i % n];
        // }
        return result;
    }
};