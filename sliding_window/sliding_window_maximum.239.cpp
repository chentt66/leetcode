// In general, whenever we encounter a new element x, we want to discard all elements that are less than x before adding x
// Time complexity: O(n) - Each element is added once and removed once (amortized)
// Space complexity: O(k) - Deque can have at most k elements
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        std::deque<int> dq; // this deque stores indices (not values) in decreasing order of their values
        // font of deque = index of maximum element in current window
        std::vector<int> res;
        // build the first window
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);

        for (int i = k; i < nums.size(); i++) {
            if (dq.front() == i - k) {
                dq.pop_front(); // this is too old for the window.
            }
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
            res.push_back(nums[dq.front()]);
        }
        
        return res;
    }
};

/*
Example: nums = [1,3,-1,-3,5,3,6,7], k = 3

PHASE 1: Building First Window (i = 0 to k-1)
==============================================

Step 1: i = 0, nums[0] = 1
---------------------------
Array:     [1*, 3, -1, -3, 5, 3, 6, 7]
Window:    [1*, 3, -1]
Deque:     []
Actions:   - Add index 0 to back
Deque:     [0]
           (front)

Step 2: i = 1, nums[1] = 3
---------------------------
Array:     [1, 3*, -1, -3, 5, 3, 6, 7]
Window:    [1, 3*, -1]
Deque:     [0]
Actions:   - Remove index 0 (nums[0]=1) from back (3 >= 1)
           - Add index 1 to back
Deque:     [1]
           (front)

Step 3: i = 2, nums[2] = -1
---------------------------
Array:     [1, 3, -1*, -3, 5, 3, 6, 7]
Window:    [1, 3, -1*]
Deque:     [1]
Actions:   - Add index 2 to back (no removal: -1 < 3)
Deque:     [1, 2]
           (front) (back)

Step 4: First window complete
------------------------------
Array:     [1, 3, -1, -3, 5, 3, 6, 7]
Window:    [1, 3, -1]
Deque:     [1, 2]
Actions:   - Add nums[1]=3 to result
Result:    [3]


PHASE 2: Sliding Window (i = k to n-1)
=======================================

Step 5: i = 3, nums[3] = -3
---------------------------
Array:     [1, 3, -1, -3*, 5, 3, 6, 7]
Window:       [3, -1, -3*]
Deque:     [1, 2]
Actions:   - Check front: dq.front()=1, i-k=0, 1≠0 (no removal)
           - Add index 3 to back (no removal: -3 < -1)
Deque:     [1, 2, 3]
           - Add nums[1]=3 to result
Result:    [3, 3]

Step 6: i = 4, nums[4] = 5
---------------------------
Array:     [1, 3, -1, -3, 5*, 3, 6, 7]
Window:          [-1, -3, 5*]
Deque:     [1, 2, 3]
Actions:   - Check front: dq.front()=1, i-k=1, 1==1 → Remove index 1 from front
Deque:     [2, 3]
           - Remove index 3 (nums[3]=-3) from back (5 >= -3)
Deque:     [2]
           - Remove index 2 (nums[2]=-1) from back (5 >= -1)
Deque:     []
           - Add index 4 to back
Deque:     [4]
           - Add nums[4]=5 to result
Result:    [3, 3, 5]

Step 7: i = 5, nums[5] = 3
---------------------------
Array:     [1, 3, -1, -3, 5, 3*, 6, 7]
Window:             [-3, 5, 3*]
Deque:     [4]
Actions:   - Check front: dq.front()=4, i-k=2, 4≠2 (no removal)
           - Add index 5 to back (no removal: 3 < 5)
Deque:     [4, 5]
           - Add nums[4]=5 to result
Result:    [3, 3, 5, 5]

Step 8: i = 6, nums[6] = 6
---------------------------
Array:     [1, 3, -1, -3, 5, 3, 6*, 7]
Window:                [5, 3, 6*]
Deque:     [4, 5]
Actions:   - Check front: dq.front()=4, i-k=3, 4≠3 (no removal)
           - Remove index 5 (nums[5]=3) from back (6 >= 3)
Deque:     [4]
           - Remove index 4 (nums[4]=5) from back (6 >= 5)
Deque:     []
           - Add index 6 to back
Deque:     [6]
           - Add nums[6]=6 to result
Result:    [3, 3, 5, 5, 6]

Step 9: i = 7, nums[7] = 7
---------------------------
Array:     [1, 3, -1, -3, 5, 3, 6, 7*]
Window:                   [3, 6, 7*]
Deque:     [6]
Actions:   - Check front: dq.front()=6, i-k=4, 6≠4 (no removal)
           - Remove index 6 (nums[6]=6) from back (7 >= 6)
Deque:     []
           - Add index 7 to back
Deque:     [7]
           - Add nums[7]=7 to result
Result:    [3, 3, 5, 5, 6, 7]

FINAL RESULT: [3, 3, 5, 5, 6, 7]

KEY OBSERVATIONS:
=================
1. Deque maintains indices in DECREASING order of their values
2. Front of deque is always the INDEX of maximum in current window
3. Elements are removed from BACK when a larger element comes
4. Elements are removed from FRONT when they fall outside window
5. Each element enters deque once and leaves deque once → O(n) time
*/



// Brute force solution
// Time complexity: O( (n-k+1)*k ), worst case is when k=2/n?
// Space complexity: O(1). result vector has constant size k.
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> maxElements;
        int n = nums.size();
        for (int i = 0; i < n - k + 1; ++i) {
            int maxInWindow = nums[i];
            for (int j = i; j < i + k; ++j) {
                maxInWindow = max(maxInWindow, nums[j]);
            }
            maxElements.push_back(maxInWindow);
        }
        return maxElements;
    }
};
