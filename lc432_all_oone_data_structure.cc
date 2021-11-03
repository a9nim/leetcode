class AllOne {
  public:
    AllOne() {
        
    }
    
    void inc(string key) {
        if (key_to_iter_.count(key) == 0) {
            if (nodes_.empty()) {
                nodes_.push_front({1, {key}}); 
                key_to_iter_[key] = nodes_.begin();
            } else {
                if (nodes_.begin()->count == 1) {
                    nodes_.begin()->keys.insert(key); 
                } else {
                    nodes_.push_front({1, {key}}); 
                }
                key_to_iter_[key] = nodes_.begin();
            }
        } else {
            std::list<Node>::iterator key_iter = key_to_iter_[key];
            std::list<Node>::iterator key_next_iter; 
            int key_count = key_iter->count;
            if (key_iter->keys.size() == 1) {
                key_next_iter = nodes_.erase(key_iter); 
            } else {
                key_iter->keys.erase(key); 
                key_next_iter = std::next(key_iter);
            }
            if (key_next_iter == nodes_.end() || key_next_iter->count != key_count + 1) {
                key_to_iter_[key] = nodes_.insert(key_next_iter, {key_count + 1, {key}}); 
            } else {
                key_next_iter->keys.insert(key);
                key_to_iter_[key] = key_next_iter;
            }
        }
    }
    
    void dec(string key) {
        std::list<Node>::iterator key_iter = key_to_iter_[key];
        std::list<Node>::iterator key_prev_iter;
        int key_count = key_iter->count;
        // Check these three conditions in the order listed below:
        // 1. Whether key_iter is nodes_.begin()
        // 2. Whether key_iter->key contains other elements
        // 3. Whether the preceding node's count is `key_iter->count - 1`, or `key_iter->count - 1` goes to 0
        if (key_iter == nodes_.begin()) {
            // Update the old `nodes_` entry.
            if (key_iter->keys.size() == 1) {
                key_iter = nodes_.erase(key_iter); 
            } else {
                key_iter->keys.erase(key);
            }
            // Update the `key_to_iter_` mapping, and add the new `nodes_` entry if needed.
            if (key_count == 1) {
                key_to_iter_.erase(key); 
            } else {
                key_to_iter_[key] = nodes_.insert(key_iter, {key_count - 1, {key}});
            }
        } else {
            key_prev_iter = std::prev(key_iter); 
            // Update the old `nodes_` entry.
            if (key_iter->keys.size() == 1) {
                key_iter = nodes_.erase(key_iter); 
            } else {
                key_iter->keys.erase(key);
            }
            // Update the `key_to_iter_` mapping, and update the new `nodes_` entry.
            if (key_count == 1) {
                key_to_iter_.erase(key);
            } else if (key_prev_iter->count == key_count - 1) {
                key_prev_iter->keys.insert(key); 
                key_to_iter_[key] = key_prev_iter;
            } else {
                key_to_iter_[key] = nodes_.insert(key_iter, {key_count - 1, {key}});
            }
        } 
    }
    
    string getMaxKey() {
        if (nodes_.empty()) {
            return ""; 
        } else {
            return *nodes_.back().keys.begin(); 
        }   
    }
    
    string getMinKey() {
        if (nodes_.empty()) {
            return ""; 
        } else {
            return *nodes_.front().keys.begin(); 
        }   
    }

  private:
    struct Node {
        int count;
        std::unordered_set<string> keys;
    };
    std::unordered_map<string, std::list<Node>::iterator> key_to_iter_;
    std::list<Node> nodes_;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
