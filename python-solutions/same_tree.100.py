# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# DFS solution
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        # base case
        if (not p and not q):
            return True
        if (not p or not q):
            return False
        if (p.val != q.val):
            return False
        # recursive case
        return (p.val == q.val) and self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right) 

# BFS solution
from collections import deque
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        # nodeQueue = []
        # nodeQueue.append((p, q))
        
        nodeQueue = deque([(p, q)])
        # nodeQueue = deque()
        # nodeQueue.append((p,q))
        while nodeQueue:
            # node1, node2 = nodeQueue.pop(0)
            node1, node2 = nodeQueue.popleft()
            if (not node1) and (not node2):
                continue
            if (not node1) or (not node2):
                return False
            if (node1.val != node2.val):
                return False
            else:
                nodeQueue.append((node1.left, node2.left))
                nodeQueue.append((node1.right, node2.right))
        return True
