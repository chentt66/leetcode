# Min heap
# O(n*logk) time
# O(n) space
import heapq
from collections import Counter
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        min_heap = []
        # count = Counter(nums)
        count = {}
        for num in nums:
            count[num] = count.get(num, 0) + 1
        for num, freq in count.items():
            heapq.heappush(min_heap, (freq, num))
            if len(min_heap) > k:
                heapq.heappop(min_heap)
        return [num for freq, num in min_heap]


# Bucket Sorts
# O(n) time: counting is O(n), building buckets is O(n), iterating buckets is O(n)
# O(n) space
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        res = []
        n = len(nums)
        from collections import Counter
        count = Counter(nums)
        buckets = [ [] for i in range(n+1) ]
        for num, cnt in count.items():
            buckets[cnt].append(num)
        for i in range(n, -1, -1):
            for num in buckets[i]:
                if len(res) == k:
                    return res
                res.append(num)
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