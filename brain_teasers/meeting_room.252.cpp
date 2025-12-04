// Sort
// O(nlogn) time
// O(1) space
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.empty()) return true;
        std::sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size() - 1; ++i) {
            if (intervals[i][1] > intervals[i + 1][0]) return false;
        }
        return true;
    }
};


// Brute Force
// O(n^2) time
// O(1) space
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1) return true;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (intervals[i][0] < intervals[j][1] && intervals[i][1] > intervals[j][0]) return false;
            }
        }
        return true;
    }
};
