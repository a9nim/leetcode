class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        std::vector<int> result;
        std::map<std::pair<int, int>, int> begin_end_to_height;
        int max_height = 0;
        for (const std::vector<int>& position : positions) {
            std::pair<int, int> cur = std::make_pair(position[0], position[0] + position[1]);
            auto iter = begin_end_to_height.lower_bound(cur); 
            if (iter != begin_end_to_height.begin()) {
                --iter;
            }
            std::map<std::pair<int, int>, int> to_add;
            int cur_max_height = 0;
            while (iter != begin_end_to_height.end()) {
                std::pair<int, int> iter_begin_end = iter->first;
                int iter_height = iter->second;
                if (iter_begin_end.first < cur.first) {
                    if (iter_begin_end.second <= cur.first) {
                        // `iter` does not overlap with the left side of `cur`.
                        ++iter; 
                        continue;
                    }
                    // `iter` overlaps with the left side of `cur`.
                    to_add[std::make_pair(iter_begin_end.first, cur.first)] = iter_height; 
                    if (iter_begin_end.second > cur.second) {
                        to_add[std::make_pair(cur.second, iter_begin_end.second)] = iter_height; 
                    }
                    cur_max_height = std::max(cur_max_height, iter_height); 
                    iter = begin_end_to_height.erase(iter);
                } else if (iter_begin_end.first >= cur.second) {
                    // `iter` does not overlap with the right side of `cur`.
                    break; 
                } else {
                    if (iter_begin_end.second > cur.second) {
                        // `iter` overlaps with the right side of `cur`. 
                        to_add[std::make_pair(cur.second, iter_begin_end.second)] = iter_height; 
                        cur_max_height = std::max(cur_max_height, iter_height); 
                        iter = begin_end_to_height.erase(iter);
                        break;
                    } else {
                        // `iter` is overshadowed by `cur`.
                        cur_max_height = std::max(cur_max_height, iter_height); 
                        iter = begin_end_to_height.erase(iter);
                    }
                }
            }
            to_add[cur] = cur_max_height + position[1];
            max_height = std::max(max_height, to_add[cur]);
            for (const auto& t : to_add) {
                 begin_end_to_height[t.first] = t.second; 
            }
            result.push_back(max_height);
        } 
        return result;
    }
};
