class RandomizedSet {
  public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (val_to_index_.count(val) != 0) {
            return false; 
        } 
        val_to_index_[val] = vals_.size();
        vals_.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (val_to_index_.count(val) == 0) {
            return false; 
        } 
        // Swap `val` with the last element in `vals_`, and then delete to achieve O(1) time complexity.
        // Update val_to_index_ first.
        int val_index = val_to_index_[val];
        int last_val_index = val_to_index_[vals_.back()];
        val_to_index_[vals_.back()] = val_index;
        val_to_index_.erase(val);
        // Then update `vals_`.
        std::swap(vals_[val_index], vals_[last_val_index]); 
        vals_.pop_back();
        return true;
    }
    
    int getRandom() {
        return vals_[rand() % vals_.size()]; 
    }
    
  private:
    std::unordered_map<int, int> val_to_index_; 
    std::vector<int> vals_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
