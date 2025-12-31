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

// Optimzied BFS
// O(n) time
// O(w) where w is the maximum width of the tree (for the queue)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if (!root) return result;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size(); // fix here to reduced memory operations.
            std::vector<int> levelValues;
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelValues.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            result.push_back(levelValues);
        }
        return result;
    }
};


// Raw version BFS
// O(n) time
// Space: O(w^²) worst case, O(w) average case
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        if (!root) return res;
        std::queue<std::vector<TreeNode*>> q;
        q.push({root});
        while (!q.empty()) {
            std::vector<TreeNode*> level = q.front(); // O(w) copy operation
            q.pop();
            std::vector<int> levelValues;
            std::vector<TreeNode*> nextLevel; // new allocation
            for (std::vector<TreeNode*>::iterator it = level.begin(); it < level.end(); ++it) {
                TreeNode* node = *it;
                levelValues.push_back(node->val);
                if (node->left) {
                    nextLevel.push_back(node->left);
                }
                if (node->right) {
                    nextLevel.push_back(node->right);
                }
            }
            res.push_back(levelValues);
            if (!nextLevel.empty()) {
                q.push(nextLevel); // O(w) copy operation
            }
        }
        return res;
    }
};
