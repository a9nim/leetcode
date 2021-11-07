class MedianFinder {
  public:
    MedianFinder() {}
    
    // This function assumes `nums` is not empty.
    double init(const std::vector<int>& nums) {
        data_ = std::multiset<int>(nums.begin(), nums.end());
        mid_ = std::next(data_.begin(), (data_.size() - 1) / 2); 
        if (data_.size() % 2 == 1) {
            return *mid_;
        } else {
            return (static_cast<double>(*mid_) + *std::next(mid_)) / 2;
        }
    }
    
    double addNum(int num) {
        if (data_.size() % 2 == 1) {
            data_.insert(num); 
            if (num < *mid_) {
                --mid_;
            }
            return (static_cast<double>(*mid_) + *std::next(mid_)) / 2;
        } else {
            data_.insert(num); 
            if (num >= *mid_) {
                ++mid_; 
            }   
            return *mid_; 
        }
    }
          
    double removeNum(int num) {
        if (data_.size() % 2 == 1) {
            if (num > *mid_) {
                --mid_; 
                data_.erase(data_.equal_range(num).first);
            } else if (num < *mid_) {
                data_.erase(data_.equal_range(num).first);
            } else {
                ++mid_;
                data_.erase(data_.equal_range(num).first);
                --mid_;
            }
            return (static_cast<double>(*mid_) + *std::next(mid_)) / 2;
        } else {
            if (num <= *mid_) {
                ++mid_;
                data_.erase(data_.equal_range(num).first);
            } else if (num > *mid_) {
                data_.erase(data_.equal_range(num).first);
            }
            return *mid_;
        }
    }
    
  private:
    std::multiset<int> data_;
    std::multiset<int>::const_iterator mid_;
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        MedianFinder mf; 
        result.push_back(mf.init(vector<int>(nums.begin(), nums.begin() + k))); 
        for (int i = k; i < nums.size(); ++i) {
            mf.addNum(nums[i]); 
            result.push_back(mf.removeNum(nums[i - k]));
        }
        return result;
    }
};
