class BstNode {
  public:
    BstNode(int val) : left_(nullptr), right_(nullptr), value_(val), count_(1), sum_left_count_(0) {}
    ~BstNode() {
        delete left_; 
        delete right_;
    }
    
    // Returns the count of the numbers smaller than `num` in its left sub-tree.
    int AddNum(int num) {
        if (num == value_) {
            ++count_;
            return sum_left_count_;
        } else if (num > value_) {
            if (right_ == nullptr) {
                right_ = new BstNode(num);
                return count_ + sum_left_count_;
            } else {
                return right_->AddNum(num) + count_ + sum_left_count_;
            }
        } else {
            ++sum_left_count_; 
            if (left_ == nullptr) {
                left_ = new BstNode(num); 
                return 0;
            } else {
                return left_->AddNum(num);
            }
        }
    } 
    
  private:
    BstNode* left_; // Owned.
    BstNode* right_;    // Owned.
    int value_;
    int count_;
    int sum_left_count_;
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        std::vector<int> result(nums.size());     
        BstNode root(nums[nums.size() - 1]);
        result[nums.size() - 1] = 0;
        for (int i = nums.size() - 2; i >= 0; --i) {
            result[i] = root.AddNum(nums[i]); 
        }
        return result;
    }
};
