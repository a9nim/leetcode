class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> sum_to_count;
        sum_to_count[0] = 1;
        int result = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum_to_count.count(sum - k) != 0) {
                result += sum_to_count[sum - k]; 
            }
            ++sum_to_count[sum];
        }
        return result;
    }
};
