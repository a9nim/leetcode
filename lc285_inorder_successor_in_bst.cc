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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* result = nullptr;
        while (root != nullptr) {
            if (p->val >= root->val) {
                root = root->right;
            } else {
                result = root;
                root = root->left;
            }
        } 
        return result;
    }
};
