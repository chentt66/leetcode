// Restriction: (1) cannot sell without having the share (2) can hold at most 1 share (3) sell with fee
// O(n) time
// O(n) space

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        std::vector<int> hold(n);
        std::vector<int> free(n, 0);
        hold[0] = -1 * prices[0];
        for (int i = 1; i < n; ++i) {
            hold[i] = max(free[i - 1] - prices[i], hold[i - 1]);
            free[i] = max(prices[i] + hold[i - 1] - fee, free[i - 1]);
        }
        return free.back();
    }
};˜