from collections import Counter
# Bucket Sorts
# O(n) time: counting is O(n), building buckets is O(n), iterating buckets is O(n)
# O(n) space
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        res = []
        n = len(nums)
        from collections import Counter
        count = Counter(nums)
        buckets = [ [] for i in range(n+1) ] # Use n+1 for convenience. There is no element in buckets[0] (each value in nums appears at least once).
        for num, cnt in count.items():
            buckets[cnt].append(num)
        for i in range(n, -1, -1):
            for num in buckets[i]:
                if len(res) == k:
                    return res
                res.append(num)
        return res

# Time: O(n log n)
# Space: O(n)
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        from collections import Counter
        count = Counter(nums) # O(n)
        arr = []
        for num, cnt in count.items():
            arr.append([cnt, num])
        arr.sort(key=lambda s: s[0], reverse=True) # O(u log u) where u = unique elements ≤ n
        res = []
        for i in range(k):
            res.append(arr[i][1])
        return res

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        from collections import Counter
        count = Counter(nums)
        arr = []
        for num, cnt in count.items():
            arr.append([cnt, num])
        arr.sort()
        res = []
        while len(res) < k:
            res.append(arr.pop()[1])
        return res


# Note:
# n = 3
# [[] for _ in range(n)]  --> [[], [], []]
# [[] * n] --> [[]]