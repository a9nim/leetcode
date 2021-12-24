class SparseVector {
public:
    
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                values_.push_back(nums[i]);
                indices_.push_back(i);
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int result = 0;
        for (int i = 0, j = 0; i < indices_.size() && j < vec.indices_.size();) {
            if (indices_[i] < vec.indices_[j]) {
                ++i; 
            } else if (indices_[i] > vec.indices_[j]) {
                ++j;
            } else {
                result += values_[i++] * vec.values_[j++]; 
            }
        }
        return result;
    }
    
    std::vector<int> values_;
    std::vector<int> indices_;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
