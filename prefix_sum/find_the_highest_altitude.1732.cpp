// note it starts at 0
// O(n) time
// O(1) space
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int peak = 0;
        int altitude = 0;
        for (int i = 0; i < gain.size(); ++i) {
            altitude += gain[i];
            peak = max(peak, altitude);
        }
        return peak;
    }
};