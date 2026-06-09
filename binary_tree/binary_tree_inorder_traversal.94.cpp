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

 // Iterative & Stack
// O(n) time: visit every node once
// O(n) space: worst case skewed treee
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> res;
        std::stack<TreeNode*> st;
        TreeNode* curr = root;
        while (curr != nullptr || !st.empty()) {
            while (curr != nullptr) {
                // traverse the left, and last in(leftmost) first out
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            res.push_back(curr->val);
            curr = curr->right; // !
        }
        return res;
    }
};

// DFS
// O(n) time because the recursive function is T(n)=2⋅T(n/2)+1.
// O(n) space
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> inorder;
        inorderDFS(root, inorder);
        return inorder;
    }
private:
    void inorderDFS(TreeNode* node, std::vector<int>& inorder) {
        if (!node) return;
        // left -> mid -> right
        inorderDFS(node->left, inorder);
        inorder.push_back(node->val);
        inorderDFS(node->right, inorder);
    }
};