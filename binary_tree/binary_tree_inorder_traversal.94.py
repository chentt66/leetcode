# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        # left, middle, right
        inorder = []
        def inorderDFS(node):
            if not node:
                return
            inorderDFS(node.left)
            inorder.append(node.val)
            inorderDFS(node.right)
        inorderDFS(root)
        return inorder