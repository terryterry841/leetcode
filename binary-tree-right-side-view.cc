/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> result;
        queue<TreeNode*> queue;
        queue.emplace(root);
        while (!queue.empty()) {
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                auto current = queue.front();
                queue.pop();
                if (i == size - 1) {
                    result.emplace_back(current->val);
                }
                if (current->left) {
                    queue.emplace(current->left);
                }
                if (current->right) {
                    queue.emplace(current->right);
                }
            }
        }
        return result;
    }
};
