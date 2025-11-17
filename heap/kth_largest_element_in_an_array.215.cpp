// Min-heap
// time: O(n*logk)
// space: O(k)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int> maxHeap; // creates a max-heap by default in C++
        for (int num : nums) {
            maxHeap.push(-num); // reverse sign -- the most negative number represents the smallest original number.
            if (maxHeap.size() > k) {
                maxHeap.pop(); // pop the largest reversed number
            }
        }
        return -1 * maxHeap.top(); // reverse back
    }
};

// Example
// For nums = [3,2,1,5,6,4] and k = 2:
// Push -3: heap = [-3]
// Push -2: heap = [-3, -2]
// Push -1: heap = [-3, -2, -1], size > 2, pop -1: heap = [-3, -2]
// Push -5: heap = [-5, -3, -2], size > 2, pop -2: heap = [-5, -3]
// Push -6: heap = [-6, -5, -3], size > 2, pop -3: heap = [-6, -5]
// Push -4: heap = [-6, -5, -4], size > 2, pop -4: heap = [-6, -5]
// Result: -(-5) = 5 (the 2nd largest element)

// Sort
// Time complexity: O(n*logn)
// Space complexity: O(logn). STL uses a hybrid of Quick Sort, Heap Sort, and Insertion Sort
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), std::greater<int>());
        return nums[k-1];
    }
};
