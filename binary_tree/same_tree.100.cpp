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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        // or simply:
        // return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// BFS solution
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
    std::queue< std::pair<TreeNode*, TreeNode*> > nodeQueue;
    nodeQueue.push({p, q});
    while (!nodeQueue.empty()) {
        pair<TreeNode*, TreeNode*> currentPair = nodeQueue.front();
        nodeQueue.pop();
        TreeNode* node1 = currentPair.first;
        TreeNode* node2 = currentPair.second;
        if (!node1 && !node2) continue;
        if (!node1 || !node2) return false;
        if (node1->val != node2->val) return false;
        nodeQueue.push( {node1->left, node2->left} );
        nodeQueue.push( {node1->right, node2->right} );
        }
        return true;
    }
};