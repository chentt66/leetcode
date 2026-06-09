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

// Iterative DFS using an explicit stack
// O(n) time
// O(n) space
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        std::vector<int> preorder;
        std::stack<TreeNode*> st({root});
        // std::stack<TreeNode*> st;
        // st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            preorder.push_back(node->val);
            if (node->right != nullptr) st.push(node->right);
            if (node->left != nullptr) st.push(node->left);
        }
        return preorder;
    }
};

// DFS
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> preorder;
        preorderDFS(root, preorder);
        return preorder;
    }
private:
    void preorderDFS(TreeNode* node, std::vector<int>& preorder) {
        // note the reference &
        if (node == nullptr) return;
        preorder.push_back(node->val);
        preorderDFS(node->left, preorder);
        preorderDFS(node->right, preorder);
    }
};