# Min-heap
# Time complexity: O(n*logk). Why?
# Space complexity: O(k).
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # import heapq
        # In Python, heapq only implements min-heaps. 
        heap = []
        for num in nums:
            heapq.heappush(heap, num)
            if len(heap) > k:
                heapq.heappop(heap) # remove the smallest element
        return heap[0] # it is a min heap, so heap[0] is the k-th largest element.

# Sort
# Time complexity: O(n*logn)
# Space complexity: O(n) in Python (Timsort algorithm)
# class Solution:
#     def findKthLargest(self, nums: List[int], k: int) -> int:
#         nums.sort(reverse=True)
#         return nums[k-1]