/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // my DFS solution
        int depth = 1;
        if (!root) return 0;
        // if (!root->left && !root->right) return 1;
        // if (!root->left) return depth + maxDepth(root->right);
        // if (!root->right) return depth + maxDepth(root->left);
        // do not need the above commented codes since the first root == nullptr check is sufficient
        return depth + max(maxDepth(root->left), maxDepth(root->right));

        // DFS solution by Claude
        // if (root == nullptr) return 0;
        // int leftDepth = maxDepth(root->left);
        // int rightDepth = maxDepth(root->right);
        // return max(leftDepth, rightDepth) + 1;
    }
};