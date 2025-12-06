// Monotonic stack
// O(n) time
// O(n) space
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<int> s; // store the indices
        int ndays = temperatures.size();
        std::vector<int> answer(ndays, 0);
        for (int i = 0; i < ndays; ++i) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                // first check !s.empty(), then whether the temperature is larger
                int lastIndex = s.top();
                s.pop();
                answer[lastIndex] = i - lastIndex;
            }
            s.push(i);
        }
        return answer;
    }
};

// Brute Force
// O(n^2) time
// O(n) space
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int ndays = temperatures.size();
        std::vector<int> answer(ndays, 0);
        for (int i = 0; i < ndays - 1; ++i) {
            for (int j = i + 1; j < ndays; ++j) {
                if (temperatures[j] > temperatures[i]) {
                    answer[i] = j - i;
                    break;
                }
            }
        }
        return answer;
    }
};