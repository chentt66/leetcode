// Two Pointers
// O(n) time
// O(1) space
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            std::swap(s[left], s[right]);
            ++left;
            --right;
        }
    }
};

// Recursion (in-place algorithm)
// O(n) time
// O(n) space because of recursion stack
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
