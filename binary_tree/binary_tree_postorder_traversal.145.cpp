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

 #include <vector>
 #include <stack>
 #include <algorithm>
 using std::vector;

// DFS recursion
// O(n) time: each node is visited once during the traversal
// O(n) space: recursion stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        postorderHelper(root, result);
        return result;
    }
private:
    void postorderHelper(TreeNode* root, std::vector<int>& result) {
        if (!root) return;
        postorderHelper(root->left, result);
        postorderHelper(root->right, result);
        result.push_back(root->val);
    }
};

// Iterative DFS using an explicit stack AND reverse!
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        std::vector<int> tmp;
        std::stack<TreeNode*> st({root});
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            tmp.push_back(node->val);
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }
        std::reverse(tmp.begin(), tmp.end()); // the acutal postorder
        return tmp;
    }
};