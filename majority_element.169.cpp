// HashMap (count frequency)
// O(n) time
// O(n) space
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> counts;
        int n = nums.size();
        for (int num : nums) {
            counts[num]++;
            if (counts[num] > n/2) return num;
        }
        return -1;
    }
};