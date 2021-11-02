class RandomizedCollection {
  public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        if (val_to_indices_.count(val) == 0) {
            val_to_indices_[val] = {static_cast<int>(vals_.size())};
            vals_.push_back(val);
            return true; 
        } else {
            val_to_indices_[val].insert(vals_.size());
            vals_.push_back(val);
            return false;
        }
    }
    
    bool remove(int val) {
        if (val_to_indices_.count(val) == 0) {
            return false;
        } 
        // Update `val_to_indices_` first.
        int val_index = *val_to_indices_[val].begin();
        val_to_indices_[val].erase(val_index);
        if (val_to_indices_[val].empty()) {
            val_to_indices_.erase(val);
        }
        // Then update `vals_`.
        if (val_index == vals_.size() - 1) {
            vals_.pop_back(); 
        } else {
            int last_val = vals_.back();
            val_to_indices_[last_val].erase(vals_.size() - 1);
            val_to_indices_[last_val].insert(val_index);
            std::swap(vals_[val_index], vals_[vals_.size() - 1]);
            vals_.pop_back();
        }
        return true;
    }
    
    int getRandom() {
        return vals_[rand() % vals_.size()];
    }

  private:
    std::unordered_map<int, std::unordered_set<int>> val_to_indices_;
    std::vector<int> vals_;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
