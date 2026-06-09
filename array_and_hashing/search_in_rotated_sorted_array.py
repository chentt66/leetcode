




class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        def binary_search(left, right):
            while left <= right:
                mid = (left + right) // 2
                if nums[mid] == target:
                    return mid
                if nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid -1
            return -1
        if nums[0] < nums[n - 1]:
            return binary_search(0, n - 1)

        left, right = 0, n - 1
        while left < right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return mid
            if nums[mid] > nums[right]:
                left = mid + 1
            else:
                right = mid
        pivot = left
        a = binary_search(0, pivot - 1)
        b = binary_search(pivot, n - 1)
        return a if a != -1 else b


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        def binary_search(left, right):
            while left <= right:
                mid = (left + right) // 2
                if nums[mid] == target:
                    return mid
                if nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid -1
            return -1

        if nums[0] < nums[n - 1]:
            return binary_search(0, n - 1)
        pivot = 0
        # 如果有重复元素？
        while nums[pivot] > nums[n - 1]:
            pivot += 1
        a = binary_search(0, pivot - 1)
        b = binary_search(pivot, n - 1)
        return a if a != -1 else b
