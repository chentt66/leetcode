# modified solution
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float("inf")] * (amount + 1)
        dp[0] = 0
        for i in range(1, amount + 1):
            for face in coins:
                if face <= i:
                    dp[i] = min(dp[i], dp[i - face] + 1)
        return dp[amount] if dp[amount] != float("inf") else -1
    
# first solution
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float("inf")] * (amount + 1)
        dp[0] = 0
        for face in coins:
            if face < (amount+1):
                dp[face] = 1 # not necessary
        for i in range(amount+1):
            for face in coins:
                if face <= i:
                    dp[i] = min(dp[i], dp[i-face]+dp[face]) # dp[face] is always 1
        return dp[amount] if dp[amount] != float("inf") else -1

# debug...
# 1. Memory Limit Exceeded due to: dp = [float("inf")] * (max(amount, max(coins)) + 1)
# 2. Should enumerate face only, not for j in range(i)


# O(S*n) time
# O(n) space
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # Initialize DP array with a value larger than any possible solution
        dp = [amount + 1] * (amount + 1) # represents the minimum coins needed for amount i
        dp[0] = 0
        for i in range(1, amount+1):
            for c in coins:
                if i - c >= 0:
                    dp[i] = min(dp[i], dp[i-c]+1)
        # >: impossible solution 
        # e.g. amount=3, coin={2}
        # dp[0]=0, dp[1]=4, dp[2]=1, dp[3]=min(dp[1]+1, dp[3])=4
        # 3 < dp[3]
        return dp[amount] if amount >= dp[amount] else -1