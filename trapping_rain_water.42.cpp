// Two pointers
// O(n) time
// O(1) space
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = 0, rightMax = 0;
        int left = 0, right = n - 1;
        int water = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] > leftMax) {
                    leftMax = height[left];
                } else {
                    water += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] > rightMax) {
                    rightMax = height[right];
                } else {
                    water += rightMax - height[right];
                }
                right--;
            }
        }
        return water;
    }
};

// O(n) time
// O(n) space
class Solution {
public:
    int trap(vector<int>& height) {
        // need extra space. optimzie later
        int n = height.size();
        std::vector<int> leftMax(n);
        std::vector<int> rightMax(n);
        leftMax[0] = height[0];
        rightMax[n - 1] = height[n - 1];
        for (int i = 1; i < n; ++i) {
            leftMax[i] = max(leftMax[i - 1], height[i - 1]);
        }
        for (int i = n - 2; i >= 0; --i) {
            rightMax[i] = max(rightMax[i + 1], height[i + 1] );
        }
        // the difficult part is the formula...
        int water = 0;
        for (int i = 0 ; i < n; ++i) {
            water += max(min(leftMax[i], rightMax[i]) - height[i], 0);
        }
        return water;
    }
};