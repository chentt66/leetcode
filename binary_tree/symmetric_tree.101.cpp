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

// DFS solution
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
        }
private:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        return (left->val == right->val) && isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
};

// BFS solution
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
    std::queue< std::pair<TreeNode*, TreeNode*> > nodeQueue;
    nodeQueue.push({root->left, root->right});
    while (!nodeQueue.empty()) {
        std::pair currentNode = nodeQueue.front();
        nodeQueue.pop();
        TreeNode* leftNode = currentNode.first;
        TreeNode* rightNode = currentNode.second;
        if (!leftNode && !rightNode ) continue;
        if (!leftNode || !rightNode ) return false;
        if (leftNode->val != rightNode->val) return false;
        nodeQueue.push({leftNode->left, rightNode->right} );
        nodeQueue.push({leftNode->right, rightNode->left});
    }
    return true;
    }
};