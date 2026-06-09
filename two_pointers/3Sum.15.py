class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        for i in range(len(nums)-2):
            if nums[i] > 0:
                break
            if ( i == 0 ) or ( nums[i-1] != nums[i] ):
                self.twoSum4Sorted(nums, i, res)
                # skip the duplicate!!! e.g. loop [-1, -1, 0, 2] is like [-1(seen), -1(skip), 0, 2]
        return res

    def twoSum4Sorted(self, nums, i, res):
        left = i + 1
        right = len(nums) - 1
        while left < right:
            s = nums[i] + nums[left] + nums[right]
            if s < 0:
                left += 1
            elif s > 0:
                right -= 1
            else:
                # e.g. now seen [-1, -1, -1, 0, 1, 2]
                res.append([nums[i], nums[left], nums[right]]) # [-1, -1, 2]
                left += 1
                right -= 1
                while ( left < right ) and ( nums[left] == nums[left-1] ):
                    # skip duplicate
                    left += 1
            
                