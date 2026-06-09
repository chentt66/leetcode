class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        dp = [False] * (n+1)
        dp[0] = True
        for i in range(1, n+1):
            for j in range(i):
                # dp[i] |= dp[j] and s[j:i] in wordDict
                if dp[j] and s[j:i] in wordDict: # note the range of s[j:i]
                    dp[i] = True
                    break
        return dp[-1]