from typing import List
# Greedy
# Prefix extremum scan
# DP
# O(n) time
# O(1) space
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices: # cannot use `if prices is None`
            return 0
        max_profit = 0
        current_min = prices[0]
        for price in prices:
            max_profit = max(price - current_min, max_profit)
            current_min = min(price, current_min)
        return max_profit
    
# Not-optimized Dynamic Programming (not that clean)
# O(n) time
# O(n) space
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        n = len(prices)
        dp = [0] * n # dp[i]: 在第 0…i 天内完成至多一次买卖的最大利润
        min_price = [0] * n # min_price[i]: 第 0…i 天的最低价格
        min_price[0] = prices[0]
        for i in range(1, n):
            min_price[i] = min(min_price[i-1], prices[i])
            dp[i] = max(dp[i-1], prices[i] - min_price[i-1])
            # equivalent: dp[i] = max(dp[i-1], prices[i] - min_price[i])
        return dp[n-1]