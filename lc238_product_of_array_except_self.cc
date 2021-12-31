class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> result(nums.size(), 1);
        int product = 1;
        for (int i = 0; i < nums.size(); ++i) {
            result[i] *= product;
            product *= nums[i];
        }
        product = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            result[i] *= product;
            product *= nums[i];
        }
        return result;
    }
};
