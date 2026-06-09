# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# O(N) time
# O(H) space
class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        def dfs(node, s):
            if not node:
                return 0
            s = (s << 1) | node.val
            # s = (s * 2) + node.val
            if (not node.left) and (not node.right):
                return s
            return dfs(node.left, s) + dfs(node.right, s)
        return dfs(root, 0)