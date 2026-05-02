// Cascading
// O(n * 2^n) time: generate all subsets and then copy them into the output list.
// O(n * 2^n) space: for a given number, it could be present or absent (i.e. binary choice) in a subset solution. As a result, for N numbers, we would have in total 2^N choices
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> combinations;
        combinations.push_back({}); // start with empty set to make the code cleaner
        for (int num : nums) {
            int size = combinations.size(); // MUST fix the size before loop, otherwise it goes inf.
            for (int i = 0; i < size; ++i) {
                std::vector<int> newSubset = combinations[i]; // must copy
                newSubset.push_back(num);
                combinations.push_back(newSubset);
            }
        }
        return combinations;
    }
};

// Backtracking
// O(n * 2^n) time
// O(n * 2^n) space
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> s;
        std::vector<int> current;
        int n = nums.size();
        backtrack(s, current, 0, nums, n);
        return s;
    }
private:
    void backtrack(std::vector<std::vector<int>>& s, std::vector<int>& current, int start, std::vector<int>& nums, int n) {
        s.push_back(current);
        for (int i = start; i < n; ++i) {
            current.push_back(nums[i]);
            backtrack(s, current, i+1, nums, n);
            current.pop_back();
        }
    }
};