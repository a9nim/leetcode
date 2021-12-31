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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> result;
        if (root == nullptr) {
            return result;
        }
        std::queue<TreeNode*> level;
        level.push(root);  
        while (!level.empty()) {
            int size = level.size(); 
            TreeNode* node = nullptr;
            while (size-- > 0) {
                node = level.front();
                level.pop();
                if (node->left != nullptr) {
                    level.push(node->left); 
                }
                if (node->right != nullptr) {
                    level.push(node->right); 
                }
            }
            result.push_back(node->val);
        }
        return result;
    }
};
