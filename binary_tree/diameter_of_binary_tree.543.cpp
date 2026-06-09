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
#include <algorithm>

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        dfs(root, diameter);
        return diameter;
    }
private:
    int dfs(TreeNode* node, int& diameter) {
        if (!node) return 0;
        int left_depth = dfs(node->left, diameter);
        int right_depth = dfs(node->right, diameter);
        diameter = std::max(diameter, left_depth + right_depth);
        return 1 + std::max(left_depth, right_depth);
    }
 };


class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        dfsHeight(root, diameter);
        return diameter;
    }

private:
    // Returns the height of the subtree rooted at node.
    // Along the way, updates maxDiameter to be the largest sum of
    // left- and right-subtree heights seen at any node.
    int dfsHeight(TreeNode* node, int& diameter) {
        if (!node) return 0;
        // Recursively get heights of left/right subtrees
        int left_height  = dfsHeight(node->left,  diameter);
        int right_height  = dfsHeight(node->right, diameter);
        // The path through this node uses left_height + right_height edges
        diameter = std::max(diameter, left_height + right_height);
        // Height is one plus the taller side
        return 1 + std::max(left_height, right_height);
    }
};