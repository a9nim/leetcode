class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int diff = 0;
        string::iterator iter = s.begin();
        while (iter != s.end()) {
            if (*iter == ')') {
                if (diff <= 0) {
                    iter = s.erase(iter); 
                } else {
                    --diff;
                    ++iter; 
                }
            } else {
                if (*iter == '(') {
                    ++diff;
                }
                ++iter; 
            }
        }
        string::reverse_iterator r_iter = s.rbegin();
        while (diff > 0) {
            if (*r_iter == '(') {
                auto iter = s.erase(r_iter.base() - 1); 
                r_iter = std::reverse_iterator(iter); 
                --diff; 
            } else { 
                ++r_iter;
            }
        }
        return s;
    }
};
