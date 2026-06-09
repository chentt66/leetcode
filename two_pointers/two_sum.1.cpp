class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> seen; // nums value, index
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            // hash look up is O(1)
            std::unordered_map<int, int>::iterator it = seen.find(complement);
            if (it != seen.end()) return {i, it->second};
            // if (seen.find(complement) != seen.end()) {
                // However, this performs a second lookup (hashing the key again) to retrieve the value
                // return {seen[complement], i}; 
            // }
            seen[nums[i]] = i;
        }
        return {};
    }
};