# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


# 关键观察：对于任意节点u，经过u的最长路径长度 = 左子树的最大深度 + 右子树的最大深度。
# 所以问题转化为：在 DFS 后序遍历过程中，每个节点计算自己的左右子树深度，更新全局最大值，同时向上返回「以自己为根的最大深度」。
# 这是个典型的「返回值服务于递归，副作用更新答案」的结构

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        diameter = 0
        def dfs(node):
            nonlocal diameter
            if not node:
                return 0
            left_depth = dfs(node.left)
            right_depth = dfs(node.right)
            diameter = max(diameter, left_depth + right_depth) # 经过当前节点的直径候选
            return 1 + max(left_depth, right_depth) # 向上汇报的深度 see #104
        dfs(root)
        return diameter