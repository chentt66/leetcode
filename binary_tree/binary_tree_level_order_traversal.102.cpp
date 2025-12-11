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

// BFS: BFS is intuitive for "level by level"
// O(n) time?
// O(n) space
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        std::vector<std::vector<int>> result;
        std::queue<std::vector<TreeNode*>> levelQueue;
        levelQueue.push({root});

        while (!levelQueue.empty()) {
            std::vector<TreeNode*> currentLevel = levelQueue.front();
            levelQueue.pop();
            std::vector<int> levelValue;
            std::vector<TreeNode*> nextLevel;
            for (std::vector<TreeNode*>::iterator it = currentLevel.begin(); it < currentLevel.end(); ++it) {
                TreeNode* currentNode = *it;
                levelValue.push_back(currentNode->val);
                if (currentNode->left) nextLevel.push_back(currentNode->left);
                if (currentNode->right) nextLevel.push_back(currentNode->right);
            }
            result.push_back(levelValue);
            if (!nextLevel.empty()) levelQueue.push(nextLevel);
        }
        return result;
    }
    
};
