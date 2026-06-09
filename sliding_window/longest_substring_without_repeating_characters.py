# Sliding window
# 维护一个窗口 [l, r],保持窗口内字符全部 distinct。r 和 l 都只向前走,绝不回退。
# O(n) time
# O(min⁡(n,Σ)) space

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:
            return 0
        window = set() # window: set[str] = set()
        l = 0
        max_length = 0
        for r in range(len(s)):
            # 把 l 往前推,直到 s[r] 不再冲突
            while s[r] in window:
                window.remove(s[l])
                l += 1
            window.add(s[r])
            max_length = max(r-l+1, max_length)
        return max_length

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        window = set()
        l, r = 0, 0
        best = 0
        n = len(s)
        while r < n:
            if s[r] not in window:
                window.add(s[r])
                r += 1
                best = max(best, r - l)
            else:
                window.remove(s[l])
                l += 1
        return best

# Sliding window + hash map



# Original solution
# O(n⋅min(n,Σ)) time, Σ是字符集大小
    # this one: ASCII，Σ=128是常数,所以实际上是 O(n)，只是常数比真正的 sliding window大。
    # 字符集无界(理论上 Σ=n)时,worst case O(n^2)
# O(min(n,Σ)) space
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:
            return 0
        n = len(s)
        max_length = 1
        length = 1
        l, r = 0, 1
        seen = {s[l]: l}
        while l < r and r < n:
            if s[r] not in seen:
                length += 1
                max_length = max(length, max_length)
                seen[s[r]] = r
                r += 1
            else:
                l = seen[s[r]] + 1
                r = l + 1
                seen = {s[l]: l}
                length = 1
        return max_length

# Slightly optimized: `while l<r` and `length == r-l` always holds
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:
            return 0
        n = len(s)
        max_length = 1
        l, r = 0, 1
        seen = {s[l]: l}
        while r < n:
            if s[r] not in seen:
                seen[s[r]] = r
                r += 1
                max_length = max(r-l, max_length)
            else:
                l = seen[s[r]] + 1
                r = l + 1
                seen = {s[l]: l}
        return max_length