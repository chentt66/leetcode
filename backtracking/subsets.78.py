# O(n*2^n) time
# O(n*2^n) space

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        s = [] # size: 2^n
        def backtrack(current, start):
            s.append(current[:])
            for i in range(start, n):
                current.append(nums[i])
                backtrack(current, i+1)
                current.pop()
        backtrack([], 0)
        return s
    
# VISUALIZATION #
# backtrack([], 0):                     ← A 层
#   for i in range(0, 3):
#     i=0: current.append(1)
#          backtrack([1], 1):           ← B 层
#            for i in range(1, 3):
#              i=1: current.append(2)
#                   backtrack([1,2], 2):  ← C 层
#                     for i in range(2, 3):
#                       i=2: current.append(3)
#                            backtrack([1,2,3], 3):  ← D 层
#                              for i in range(3, 3):  (空)
#                              return  ← D 返回
#                            current.pop()   ← C 层的代码,弹出 3
#                     (C 的 for 循环结束)
#                     return  ← C 返回
#                   current.pop()   ← B 层的代码,弹出 2
#              i=2: current.append(3)
#                   backtrack([1,3], 3):  ← 新的 D 层
#                   ...


# backtrack([], 0)                       s = [[]]
# ├ i=0: append(1)  → current=[1]
# │ backtrack([1], 1)                    s = [..., [1]]
# │ ├ i=1: append(2)  → current=[1,2]
# │ │ backtrack([1,2], 2)                s = [..., [1,2]]
# │ │ ├ i=2: append(3)  → current=[1,2,3]
# │ │ │ backtrack([1,2,3], 3)            s = [..., [1,2,3]]
# │ │ │ (range(3,3) 是空的, 直接 return)
# │ │ └ ★ pop()  → current=[1,2]          ← 弹出 3
# │ │ (循环结束, return)
# │ ├ ★ pop()  → current=[1]              ← 弹出 2
# │ ├ i=2: append(3)  → current=[1,3]
# │ │ backtrack([1,3], 3)                s = [..., [1,3]]
# │ │ (return)
# │ └ ★ pop()  → current=[1]              ← 弹出 3
# │ (循环结束, return)
# ├ ★ pop()  → current=[]                 ← 弹出 1
# ├ i=1: append(2)  → current=[2]
# │ backtrack([2], 2)                    s = [..., [2]]   ◀◀◀ [2] 在这里加入!
# │ ├ i=2: append(3)  → current=[2,3]
# │ │ backtrack([2,3], 3)                s = [..., [2,3]]
# │ └ ★ pop()  → current=[2]
# │ (return)
# ├ ★ pop()  → current=[]                 ← 弹出 2
# ├ i=2: append(3)  → current=[3]
# │ backtrack([3], 3)                    s = [..., [3]]
# └ ★ pop()  → current=[]