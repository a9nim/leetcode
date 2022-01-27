class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>::iterator lb = std::lower_bound(nums.begin(), nums.end(), target);
        if (lb == nums.end() || *lb != target) {
           return {-1, -1};
        }
        vector<int>::iterator ub = std::upper_bound(lb, nums.end(), target);
        return {static_cast<int>(lb - nums.begin()), static_cast<int>(ub - nums.begin() - 1)};
    }
};
