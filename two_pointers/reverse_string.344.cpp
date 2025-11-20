// Two pointers Iteration
// O(n) time: swap n/2 elements
// O(1) space
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
};


// Recursion (in-place algorithm)
// O(n) time
// 0(n) space because of recursion stack
class Solution {
public:
    void reverseString(vector<char>& s) {
        reverseHelper(s, 0, s.size() - 1);
    }
    
private:
    void reverseHelper(vector<char>& s, int left, int right) {
        // base case
        if (left >= right) return;
        // recursive call
        std::swap(s[left], s[right]);
        reverseHelper(s, left + 1, right - 1);
    }
};
