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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        
        if (key < root->val) {
            root->left = deleteNode(root->left, key);     
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key); 
        } else {
            if (root->left == nullptr) {
                return root->right; 
            } else if (root->right == nullptr) {
                return root->left; 
            } else {
                // Find the in-order successor.
                TreeNode* prev = root->right;
                if (prev->left == nullptr) {
                    prev->left = root->left;  
                    return prev;
                }
                TreeNode* cur = prev->left;
                while (cur->left != nullptr) {
                    prev = cur;
                    cur = cur->left;
                }
                prev->left = cur->right;
                cur->left = root->left;
                cur->right = root->right;
                delete root;
                return cur;
            }
        }
        return root;
    }
};
