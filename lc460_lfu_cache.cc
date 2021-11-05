class LFUCache {
  public:
    LFUCache(int capacity) : capacity_(capacity) {
        
    }
    
    struct FreqNode {
        int freq;
        std::list<int> keys;
    };
    
    struct KeyNode {
        int value;
        std::list<FreqNode>::iterator freq_node_iter; 
        std::list<int>::iterator key_iter;
    };
    
    int get(int key) {
        if (capacity_ == 0) {
            return -1; 
        }
        auto key_iter = key_to_iter_.find(key);
        if (key_iter == key_to_iter_.end()) {
            return -1;
        }
        touch(key_iter, key);
        return key_iter->second.value;
    }
    
    void put(int key, int value) {
        // Check for eviction.
        if (capacity_ == 0) {
            return;
        }
        auto key_iter = key_to_iter_.find(key);
        if (key_iter == key_to_iter_.end() && key_to_iter_.size() == capacity_) {
            FreqNode& lowest_freq_node = freq_nodes_.front(); 
            int delete_key = lowest_freq_node.keys.back();
            if (lowest_freq_node.keys.size() == 1) {
                freq_nodes_.pop_front(); 
            } else {
                lowest_freq_node.keys.pop_back();
            }
            key_to_iter_.erase(delete_key);
        }
        if (key_iter == key_to_iter_.end()) {
            // Add new entry in freq_nodes_.
            if (freq_nodes_.begin()->freq == 1) {
                freq_nodes_.begin()->keys.push_front(key); 
            } else {
                freq_nodes_.push_front({1, {key}});
            }
            key_to_iter_[key] = {value, freq_nodes_.begin(), freq_nodes_.front().keys.begin()};
        } else {
            touch(key_iter, key);
            key_iter->second.value = value;
        }
        return;
    }
    
    void touch(std::unordered_map<int, KeyNode>::iterator key_iter, int key) {
        KeyNode& key_node = key_iter->second;
        // Delete old node in `freq_nodes_`.
        std::list<FreqNode>::iterator old_freq_node_iter = key_node.freq_node_iter;
        std::list<FreqNode>::iterator new_freq_node_iter;
        int old_freq = old_freq_node_iter->freq;
        if (old_freq_node_iter->keys.size() == 1) {
            new_freq_node_iter = freq_nodes_.erase(old_freq_node_iter); 
        } else {
            old_freq_node_iter->keys.erase(key_node.key_iter); 
            new_freq_node_iter = std::next(old_freq_node_iter);
        }
        // Add new node to `freq_nodes_`.
        if (new_freq_node_iter != freq_nodes_.end() && new_freq_node_iter->freq == old_freq + 1) {
            new_freq_node_iter->keys.push_front(key); 
        } else {
            new_freq_node_iter = freq_nodes_.insert(new_freq_node_iter, {old_freq + 1, {key}}); 
        }
        // Update `key_to_iter_` to point to the new node.
        key_node.freq_node_iter = new_freq_node_iter;
        key_node.key_iter = new_freq_node_iter->keys.begin();
        return;
    }

  private:
    std::unordered_map<int, KeyNode> key_to_iter_;
    std::list<FreqNode> freq_nodes_;
    int capacity_;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
