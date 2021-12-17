// Quick sort.
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(0, nums.size(), nums);
        return nums;
    }
    
    void quickSort(int begin, int end, vector<int>& nums) {
        if (begin + 1 >= end) {
            return;
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
        quickSort(begin, right + 1, nums);
        quickSort(left, end, nums);
        return;
    }
};

// Merge sort.
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        std::vector<int> cache(nums.size());
        mergeSort(0, nums.size(), nums, cache); 
        return nums;
    }
    
    void mergeSort(int begin, int end, std::vector<int>& nums, std::vector<int>& cache) {
        if (begin + 1 >= end) {
            return;
        }
        int mid = begin + (end - begin) / 2;
        mergeSort(begin, mid, nums, cache);
        mergeSort(mid, end, nums, cache);
        merge(begin, mid, end, nums, cache);
        return; 
    }
    
    void merge(int begin, int mid, int end, std::vector<int>& nums, std::vector<int>& cache) {
        for (int i = begin; i < end; ++i) {
            cache[i] = nums[i];
        }
        int merged = begin;
        int left = begin;
        int right = mid;
        while (left < mid && right < end) {
            if (cache[left] <= cache[right]) {
                nums[merged++] = cache[left++]; 
            } else {
                nums[merged++] = cache[right++]; 
            }
        }
        while (left < mid) {
            nums[merged++] = cache[left++];
        }
        return;
    }
};

// Bubble sort.
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for (int i = nums.size() - 1; i > 0; --i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] > nums[j + 1]) {
                    std::swap(nums[j], nums[j + 1]);
                }
            }
        }
        return nums;
    }
};
