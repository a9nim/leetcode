class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 1; i > 0; --i) {
            if (nums[i] <= nums[i - 1]) {
                continue; 
            } 
            std::reverse(nums.begin() + i, nums.end()); 
            std::vector<int>::iterator greater_num_iter = std::upper_bound(nums.begin() + i, nums.end(), nums[i - 1]);
            std::swap(nums[i - 1], *greater_num_iter);
            return;
        }        
        std::reverse(nums.begin(), nums.end());
        return;
    }
};
