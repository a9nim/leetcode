class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        std::vector<int> result(nums.size());
        std::vector<std::pair<int, int>> nums_with_original_indices(nums.size());
        std::vector<std::pair<int, int>> cache(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            nums_with_original_indices[i] = std::make_pair(nums[i], i); 
        } 
        mergeSort(0, nums.size(), nums_with_original_indices, cache, result);
        return result;
    }
    
    void mergeSort(int begin, int end, std::vector<std::pair<int, int>>& nums_with_original_indices, std::vector<std::pair<int, int>>& cache, std::vector<int>& result) {
        if (begin + 1 >= end) {
            return;
        }
        int mid = (begin + end) / 2;
        mergeSort(begin, mid, nums_with_original_indices, cache, result);
        mergeSort(mid, end, nums_with_original_indices, cache, result);
        merge(begin, mid, end, nums_with_original_indices, cache, result);
        return;
    }
    
    void merge(int begin, int mid, int end, std::vector<std::pair<int, int>>& nums_with_original_indices, std::vector<std::pair<int, int>>& cache, std::vector<int>& result) {
        // Copy [begin, end) to cache first.
        for (int i = begin; i < end; ++i) {
            cache[i] = nums_with_original_indices[i];
        }
        
        int merged = begin;
        int left = begin;
        int right = mid;
        while (left < mid && right < end) {
            if (cache[left].first <= cache[right].first) {
                nums_with_original_indices[merged] = cache[left];
                result[cache[left].second] += merged - left;
                ++left;
            } else {
                nums_with_original_indices[merged] = cache[right];
                ++right;
            }
            ++merged;
        }
        while (left < mid) {
            nums_with_original_indices[merged] = cache[left];
            result[cache[left].second] += merged - left;
            ++left;
            ++merged;
        }
    }
};
