def linearSearch(nums, target):
    return

def binarySearch(nums, target):
    left = 0
    right = len(nums) - 1
    # Need <=: when left == right, there's still one element to check!
    while left <= right:
        mid = (left + right ) // 2 # floor
        if nums[mid] == target:
            return mid
        if nums[mid] < target:
            left = mid + 1
        else:
            right = mid -1
    return -1