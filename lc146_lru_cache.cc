class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {
    }
    
    int get(int key) {
        auto key_iter_pair_iter = key_to_iter_.find(key);
        if (key_iter_pair_iter == key_to_iter_.end()) {
            return -1;
        }
        auto key_iter = key_iter_pair_iter->second;
        int value = key_iter->second;
        key_value_pairs_.erase(key_iter);
        key_value_pairs_.push_front(std::make_pair(key, value)); 
        key_to_iter_[key] = key_value_pairs_.begin();
        return value;
    }
    
    void put(int key, int value) {
        auto key_iter_pair_iter = key_to_iter_.find(key);
        if (key_iter_pair_iter == key_to_iter_.end()) {
            if (key_value_pairs_.size() == capacity_) {
                key_to_iter_.erase(key_value_pairs_.back().first);
                key_value_pairs_.pop_back();
            } 
            key_value_pairs_.push_front(std::make_pair(key, value));
            key_to_iter_[key] = key_value_pairs_.begin();
        } else {
            auto key_iter = key_iter_pair_iter->second;
            key_value_pairs_.erase(key_iter);
            key_value_pairs_.push_front(std::make_pair(key, value));
            key_to_iter_[key] = key_value_pairs_.begin();
        }
        return;
    }
  private:
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> key_to_iter_; 
    std::list<std::pair<int, int>> key_value_pairs_;
    int capacity_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
