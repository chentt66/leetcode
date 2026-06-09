class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        // dp[i][j] = min ops for word1[:i] -> word2[:j]
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
        // base cases
        for (int i = 0; i <= m; ++i) {
            // delete all chars from word1
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; ++j) {
            // insert all chars into word1
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min( {dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]} );
                    // diag, top, left
                    // replace, insert, delete?
                }
            }
        }
        return dp[m][n];
    }
};