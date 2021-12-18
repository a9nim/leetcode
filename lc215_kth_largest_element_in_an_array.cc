class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(0, nums.size(), nums, nums.size() + 1 - k);
    }
   
    int quickSelect(int begin, int end, std::vector<int>& nums, int kth_smallest) {
        if (begin + 1 >= end) {
            return nums[begin]; 
        }
        std::pair<int, int> left_right = partition(begin, end, nums);
        int left = left_right.first;
        int right = left_right.second;
        int kth_smallest_index = kth_smallest - 1;
        if (left == right + 1) {
            if (right >= kth_smallest_index) {
                return quickSelect(begin, right + 1, nums, kth_smallest);
            } else {
                return quickSelect(left, end, nums, kth_smallest);
            }
        } else {
            int partition_index = right + 1;
            if (partition_index < kth_smallest_index) {
                return quickSelect(partition_index + 1, end, nums, kth_smallest);
            } else if (partition_index > kth_smallest_index) {
                return quickSelect(begin, partition_index, nums, kth_smallest); 
            } else {
                return nums[partition_index];
            }
        }
    }
    
    std::pair<int, int> partition(int begin, int end, std::vector<int>& nums) {
        if (begin + 1 >= end) {
            return std::make_pair(end, begin);
        } 
        int pivot = nums[begin + rand() % (end - begin)];
        int left = begin;
        int right = end - 1;
        while (left <= right) {
            while (left < end && nums[left] < pivot) {
                ++left;
            }
            while (right >= begin && nums[right] > pivot) {
                --right; 
            }
            if (left > right) {
                break; 
            }
            std::swap(nums[left++], nums[right--]);
        }
        return std::make_pair(left, right);
    }
};
