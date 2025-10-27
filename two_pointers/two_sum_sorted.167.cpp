class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while (left <= right) {
            int s = numbers[left] + numbers[right];
            // 1-indexed!
            if (s == target) return std::vector<int>{left + 1, right + 1};
            if (s < target) left++;
            if (s > target) right--;
        }
        return std::vector<int> {-1, -1};
    }
};
