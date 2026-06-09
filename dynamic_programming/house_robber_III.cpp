class Solution {
public:
    int rob(TreeNode* root) {
        std::pair<int,int> res = dfs(root);
        return std::max(res.first, res.second);
    }
private:
    std::pair<int,int> dfs(TreeNode* node) {
        if (!node) return {0, 0};

        std::pair<int,int> left  = dfs(node->left);
        std::pair<int,int> right = dfs(node->right);

        // OR:
        // auto [rob_left, skip_left] = dfs(node->left);

        int rob  = node->val + left.second + right.second;
        int skip = std::max(left.first, left.second)
                 + std::max(right.first, right.second);

        return {rob, skip};
    }
};

