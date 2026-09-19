class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;
        std::vector<std::string> rows(numRows);
        int direction;
        int r = 0;
        for (char c : s) {
            rows[r] += c;
            if (r == 0) {
                direction = 1;
            } 
            else if (r == numRows - 1) {
                direction = -1;
            }
            r += direction;
        }

        std::string zigzag;
        for (const string& r : rows) {
            zigzag += r;
        }
        return zigzag;
    }
};