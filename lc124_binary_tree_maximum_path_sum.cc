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
    int maxPathSum(TreeNode* root) {
        int result = std::numeric_limits<int>::min();    
        maxPathSumRecur(root, result);
        return result;
    }
    
    int maxPathSumRecur(TreeNode* node, int& max) {
        if (node == nullptr) {
            return std::numeric_limits<int>::min();
        }
        int left_max = std::max(0, maxPathSumRecur(node->left, max));
        int right_max = std::max(0, maxPathSumRecur(node->right, max));
        int sum = node->val + left_max + right_max;
        if (sum > max) {
            max = sum;
        }
        return node->val + std::max(left_max, right_max);
    }
};
