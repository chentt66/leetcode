#include <vector>
#include <stack>
using std::vector;
using std::stack;

// Monotonic stack
// O(n) time
// O(n) space
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<int> mstack; // store the indices
        int n = temperatures.size();
        std::vector<int> deltas(n, 0);
        for (int i = 0; i < n; ++i) {
            while (!mstack.empty() && temperatures[i] > temperatures[mstack.top()]) {
                // first check !mstack.empty(), then check whether this temperature is higher
                int j = mstack.top();
                mstack.pop();
                deltas[j] = i - j;
            }
            mstack.push(i);
        }
        return deltas;
    }
};

// use std::vector instead of std::stack
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> deltas(n, 0);
        vector<int> stk;
        stk.reserve(n); //
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && temperatures[i] > temperatures[stk.back()]) {
                int j = stk.back();
                stk.pop_back();
                deltas[j] = i - j;
            }
            stk.push_back(i);
        }
        return deltas;
    }
};

// Brute Force
// O(n^2) time
// O(n) space
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        std::vector<int> deltas(n, 0);
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (temperatures[j] > temperatures[i]) {
                    deltas[i] = j - i;
                    break;
                }
            }
        }
        return deltas;
    }
};