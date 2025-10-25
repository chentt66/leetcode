// O(log n) time complexity
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstOccurrence = this->findBound(nums, target, true);
        if (firstOccurrence == -1) {
            return vector<int>{-1, -1};
        }
        int lastOccurrence = this->findBound(nums, target, false);
        return vector<int>{firstOccurrence, lastOccurrence};
    }

private:
    int findBound(vector<int>& nums, int target, bool searchFirst) {
        int N = nums.size();
        int begin = 0, end = N - 1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (nums[mid] == target) {
                if (searchFirst) {
                    if (mid == begin || nums[mid - 1] != target) {
                        return mid;
                    }
                    end = mid - 1;
                } else {
                    if (mid == end || nums[mid + 1] != target) {
                        return mid;
                    }
                    begin = mid + 1;
                }
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        return -1;
    }
};

// O(n) time complexity
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                int start = mid;
                int end = mid;
                while (start >= 0 && nums[start] == target) {
                    start--;
                }
                while (end <= nums.size()-1 && nums[end] == target) {
                    end++;
                }
                return std::vector<int> {start+1, end-1};
            }
            if (nums[mid] < target) {
                left = mid + 1;
            }
            if (nums[mid] > target) {
                right = mid - 1;
            }
    }
        return std::vector<int> {-1, -1};
    }
};