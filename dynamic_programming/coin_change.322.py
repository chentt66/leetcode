# O(S*n) time
# O(n) space
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # Initialize DP array with a value larger than any possible solution
        dp = [amount + 1] * (amount + 1) # represents the minimum coins needed for amount i
        dp[0] = 0
        # dp[i] = min(dp[i], dp[i - c] + 1)
        for i in range(1, amount+1):
            for c in coins:
                if i - c >= 0:
                    dp[i] = min(dp[i], dp[i-c]+1)
        # >: impossible solution e.g. amount=3, coin={5}, dp[1]=dp[2]=dp[3]=dp[4]=5>3, non solution
        return dp[amount] if dp[amount] <= amount else -1