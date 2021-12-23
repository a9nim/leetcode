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
    int pathSum(TreeNode* root, int targetSum) {
        int result = 0;
        std::unordered_map<int, int> sum_to_count;
        sum_to_count[0] = 1; 
        preorderTraversal(root, 0, targetSum, sum_to_count, &result);
        return result;
    }
    
    void preorderTraversal(TreeNode* node, int cur_sum, int target_sum, std::unordered_map<int, int>& sum_to_count, int* result) {
        if (node == nullptr) {
            return; 
        } 
        cur_sum += node->val;
        if (sum_to_count.count(cur_sum - target_sum) != 0) {
            *result += sum_to_count[cur_sum - target_sum];
        } 
        ++sum_to_count[cur_sum];
        preorderTraversal(node->left, cur_sum, target_sum, sum_to_count, result);
        preorderTraversal(node->right, cur_sum, target_sum, sum_to_count, result);
        --sum_to_count[cur_sum];
        return;
    }
};
