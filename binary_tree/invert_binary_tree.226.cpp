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

// BFS
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        std::queue<TreeNode*> nodeQueue;
        if (!root) return root;
        nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;
            if (node->left) nodeQueue.push(node->left);
            if (node->right) nodeQueue.push(node->right);
        }
        return root;
    }
};