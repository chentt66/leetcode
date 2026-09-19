# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Recursively
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        # base
        if not root:
            return True
        # recursion
        def dfs(left_node, right_node):
            if not left_node and not right_node:
                return True
            if not left_node or not right_node:
                return False
            if left_node.val != right_node.val:
                return False
            return dfs(left_node.left, right_node.right) and dfs(left_node.right, right_node.left)
        return dfs(root.left, root.right)
    
# Iteratively
