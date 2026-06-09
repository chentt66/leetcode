# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# DFS
# Time: O(n)
# Space: O(n)
    # Output: level_order ends up holding all n values across its sublists — O(n).
    # Auxiliary (the recursion stack): the call stack holds one frame per ancestor of the currently-visited node, so its depth equals the current node's depth. The maximum stack depth is therefore hh h, the height of the tree.
        # Balanced tree: h=O(logn)
        # Skewed tree(degenerate, linked-list-shaped): h=O(n)
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        level_order = []
        def dfs(node, depth):
            if node is None:
                return
            if depth == len(level_order):
                level_order.append([])
            level_order[depth].append(node.val)
            dfs(node.left, depth+1)
            dfs(node.right, depth+1)
        dfs(root, 0)
        return level_order
    
# BFS
# O(n) time: Every node is enqueued exactly once and dequeued exactly once over the entire run
# O(n) space
    # Auxiliary space (excluding output): O(w) where w is max width of tree, worst-case O(n)
    # Total space including output: O(n)
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        level_order = []
        if root is None:
            return level_order
        from collections import deque
        q = deque([root])
        # Issue: while q is not None. deque([]) is not None is always True.
        while len(q) > 0:
        # OR: while q
            n = len(q) # important
            level = []
            for i in range(n):
                node = q.popleft()
                level.append(node.val)
                if node.left is not None:
                    q.append(node.left)
                if node.right is not None:
                    q.append(node.right)
            level_order.append(level)
        return level_order