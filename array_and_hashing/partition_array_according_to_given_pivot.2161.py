

# Two pointers
# O(n) time
# O(n) space
class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        n = len(nums)
        left = 0
        right = n - 1
        result = [pivot] * n
        for i in range(n):
            if nums[i] < pivot:
                result[left] = nums[i]
                left += 1
            if nums[n-1-i] > pivot:
                result[right] = nums[n-1-i]
                right -= 1
        return result
    


class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        less, equal, greater = [], [], []
        for num in nums:
            if num < pivot:
                less.append(num)
            elif num == pivot:
                equal.append(pivot)
            else:
                greater.append(num)
        return less + equal + greater
    


# raw solution ...
