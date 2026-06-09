# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# DFS
# O(n) time:
    # Each node is visited exactly once. 
    # For every non-null node, preorderDFS does a constant amount of work — **one push_back plus two recursive calls** — all O(1). 
    # With n nodes, that's n constant-time operations, giving O(n).
# O(n) space:
    # Space: the depth of the recursion call stack.
    # Worst when degenerates h=n; best when balanced h=log(n).
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        preorder = []
        def preorderDFS(node):
            if node is None:
                return
            preorder.append(node.val)
            preorderDFS(node.left)
            preorderDFS(node.right)
        preorderDFS(root)
        return preorder

# Iterative DFS using an explicit stack
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        preorder = []
        st = [root]
        while st:
            node = st.pop()
            preorder.append(node.val)
            if node.right:
                st.append(node.right)
            if node.left:
                st.append(node.left)
        return preorder