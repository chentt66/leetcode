// In place reversal
// O(n) time
// O(1) space
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
    }
};

// Manual reversal
// O(n) time
// O(1) space
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverseHelper(nums, 0, n - 1);
        reverseHelper(nums, 0, k - 1);
        reverseHelper(nums, k, n - 1);
    }
private:
    void reverseHelper(std::vector<int>& nums, int left, int right) {
        while (left < right) {
            // std::swap(nums[left], nums[right]);
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
    }
};