# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


# DFS
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        postorder = []
        def postorderDFS(node):
            if not node:
                return
            postorderDFS(node.left)
            postorderDFS(node.right)
            postorder.append(node.val)
        postorderDFS(root)
        return postorder

# Iterative DFS using an explicit stack AND reverse!
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        tmp = [] # root, right, left
        st = [root]
        while st:
            node = st.pop()
            tmp.append(node.val)
            if node.left:
                st.append(node.left)
            if node.right:
                st.append(node.right)
        # reverse
        postorder = tmp[::-1]
        return postorder