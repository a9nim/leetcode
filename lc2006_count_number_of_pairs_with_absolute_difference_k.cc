class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int num_counts[101] = {};
        for (int num : nums) {
            ++num_counts[num];
        }
        
        int answer = 0;
        for (int i = 1; i + k < 101; ++i) {
            answer += num_counts[i] * num_counts[i + k];
        }
        return answer;
    }
};
