class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        std::vector<long> sums(nums.size() + 1);
        long sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sums[i] = sum;
            sum += nums[i];
        }
        sums[nums.size()] = sum;
        
        int result = 0;
        std::vector<long> cache(sums.size());
        mergeSort(sums, 0, sums.size(), lower, upper, cache, result);
        return result;
    }
    
    void mergeSort(std::vector<long>& sums, int begin, int end, int lower, int upper, std::vector<long>& cache, int& result) {
        if (end <= begin + 1) {
            return; 
        } 
        int mid = (begin + end) / 2;
        mergeSort(sums, begin, mid, lower, upper, cache, result);
        mergeSort(sums, mid, end, lower, upper, cache, result);
        merge(sums, begin, mid, end, lower, upper, cache, result);
        return;
    }
    
    void merge(std::vector<long>& sums, int begin, int mid, int end, int lower, int upper, std::vector<long>& cache, int& result) {
        // Store values to cache to be used during merging.
        for (int i = begin; i < end; ++i) {
            cache[i] = sums[i];
        }
        
        int merged = begin;
        int left = begin;
        int right = mid;
        // Stores the index of the first item in [mid, end) that satisfies `sums[right_lower] - sums[left] >= lower`.
        int right_lower = mid;
        // Stores the index of the first item in [mid, end) that satisfies `sums[right_upper] - sums[left] > upper`.
        // This way, for every `left` item in [begin, mid), there would be `right_upper - right_lower` items whose diff against `left` lies in [lower, upper].
        int right_upper = mid;
        while (left < mid && right < end) {
            if (cache[left] <= cache[right]) {
                while (right_lower < end && cache[right_lower] - cache[left] < lower) {
                    ++right_lower; 
                }
                while (right_upper < end && cache[right_upper] - cache[left] <= upper) {
                    ++right_upper; 
                }
                result += right_upper - right_lower;
                sums[merged++] = cache[left++]; 
            } else {
                sums[merged++] = cache[right++]; 
            }
        }
        while (left < mid) {
            while (right_lower < end && cache[right_lower] - cache[left] < lower) {
                ++right_lower; 
            }
            while (right_upper < end && cache[right_upper] - cache[left] <= upper) {
                ++right_upper; 
            }
            result += right_upper - right_lower;
            sums[merged++] = cache[left++];
        }
        return;
    }
};
