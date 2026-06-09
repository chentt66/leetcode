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

// DFS
// O(n1 * n2) time. n_i: number of nodes in tree_i
// O(h1 * h2) space
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (isSameTree(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
private:
    bool isSameTree(TreeNode* tree1, TreeNode* tree2) {
        if (!tree1 && !tree2) return true;
        if (!tree1 || !tree2) return false;
        return (tree1->val == tree2->val) && isSameTree(tree1->left, tree2->left) && isSameTree(tree1->right, tree2->right);
    }
};