# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# O(n) time
# O(n) space, worst when h = n.
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        def dfs(node):
            if not node:
                return (0, 0)
            rob_left, skip_left = dfs(node.left)
            rob_right, skip_right = dfs(node.right)
            rob = node.val + skip_left + skip_right # rob here → skip children
            skip = max(rob_left, skip_left) + max(rob_right, skip_right) # skip here → best of each child
            return (rob, skip)
        return max(dfs(root))