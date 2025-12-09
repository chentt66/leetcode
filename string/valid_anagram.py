# Counter frequency
# O(n + m) time
# O(1) space. number of char is bounded
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_count= {}
        for char in s:
            s_count[char] = s_count.get(char, 0) + 1
        for char in t:
            if (char not in s_count.keys() or s_count[char] <= 0):
                return False
            else:
                s_count[char] -= 1
        for char in s_count.keys():
            if s_count[char] != 0:
                return False
        return True
    # return collections.Counter(s) == collections.Counter(t)

# Sort
# O(n*logn) time
# O(n) space: python sorted...?
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)