# Min heap
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
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        res = []
        n = len(nums)
        num_count = {}
        for num in nums:
            num_count[num] = num_count.get(num, 0) + 1
        buckets = [[] for i in range(n+1)]
        for num, cnt in num_count.items():
            buckets[cnt].append(num)

        for i in range(n, -1, -1):
            for num in buckets[i]:
                if len(res) == k:
                    return res
                res.append(num)
        return res

# n = 3
# [[] for _ in range(n)] 
# [[], [], []]
# [[] * n]
# [[]]