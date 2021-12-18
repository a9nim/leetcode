class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        quickSelect(0, points.size(), points, k);
        return std::vector<std::vector<int>>(points.begin(), points.begin() + k);
    }
    
    int quickSelect(int begin, int end, std::vector<std::vector<int>>& points, int kth_smallest) {
        if (begin + 1 >= end) {
            return begin; 
        }
        std::pair<int, int> left_right = partition(begin, end, points);
        int left = left_right.first;
        int right = left_right.second;
        int kth_smallest_index = kth_smallest - 1;
        if (left == right + 1) {
            if (right == kth_smallest_index) {
                return right;
            } else if (right > kth_smallest_index) {
                return quickSelect(begin, right + 1, points, kth_smallest);
            } else {
                return quickSelect(left, end, points, kth_smallest);
            }
        } else {
            int partition_index = right + 1;
            if (partition_index < kth_smallest_index) {
                return quickSelect(partition_index + 1, end, points, kth_smallest);
            } else if (partition_index > kth_smallest_index) {
                return quickSelect(begin, partition_index, points, kth_smallest); 
            } else {
                return partition_index;
            }
        }
    }
    
    std::pair<int, int> partition(int begin, int end, std::vector<std::vector<int>>& points) {
        if (begin + 1 >= end) {
            return std::make_pair(end, begin);
        } 
        std::vector<int> pivot = points[begin + rand() % (end - begin)];
        int left = begin;
        int right = end - 1;
        while (left <= right) {
            while (left < end && compare(points[left], pivot) < 0) {
                ++left;
            }
            while (right >= begin && compare(points[right], pivot) > 0) {
                --right; 
            }
            if (left > right) {
                break; 
            }
            std::swap(points[left++], points[right--]);
        }
        return std::make_pair(left, right);
    }
    
    int compare(std::vector<int>& a, std::vector<int>& b) {
        int distance_a = a[0] * a[0] + a[1] * a[1];
        int distance_b = b[0] * b[0] + b[1] * b[1];
        if (distance_a < distance_b) {
            return -1; 
        } else if (distance_a > distance_b) {
            return 1; 
        } else {
            return 0;
        }
    }
};
