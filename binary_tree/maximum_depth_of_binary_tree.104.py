from typing import Optional
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# DFS
# O(n) time
# Auxiliary space: O(h)
    # Worst when skewd/degenerate: O(n)
    # Best when balanced: O(log n)
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        left_depth = self.maxDepth(root.left)
        right_depth = self.maxDepth(root.right)
        return 1 + max(left_depth, right_depth)

# BFS
# O(n) time
# Auxiliary space: O(w)
    # Worst when complete binary O(n)
    # Best when skewed: O(1)
# Good when: 返回深度超过 k 的第一个节点



# Stack
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        stack = [(root, 1)]                  # (node, depth_at_that_node)
        max_d = 0
        while stack:
            node, d = stack.pop()
            max_d = max(max_d, d)
            if node.left is not None:
                stack.append((node.left, d + 1))
            if node.right is not None:
                stack.append((node.right, d + 1))
        return max_d