class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int nums_size = nums.size();
        std::vector<std::vector<int>> cache(nums_size + 1, std::vector<int>(nums_size + 1, -1)); 
        return maxCoinsRecur(0, nums_size, nums_size, nums, cache); 
    }
    
    int maxCoinsRecur(int begin, int end, int nums_size, const std::vector<int>& nums, std::vector<std::vector<int>>& cache) {
        if (cache[begin][end] != -1) {
            return cache[begin][end];
        }
        int result = 0;
        if (begin == end) {
            result = 0;
        } else {
            int left_num = begin - 1 < 0 ? 1 : nums[begin - 1];
            int right_num = end == nums_size ? 1 : nums[end];
            for (int i = begin; i < end; ++i) {
                int split_at_i = maxCoinsRecur(begin, i, nums_size, nums, cache) + left_num * nums[i] * right_num + maxCoinsRecur(i + 1, end, nums_size, nums, cache);
                result = std::max(result, split_at_i);
            }
        }
        cache[begin][end] = result;
        return result;
    }
};
