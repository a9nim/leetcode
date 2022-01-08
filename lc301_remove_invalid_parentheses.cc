class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int extra_left = 0;  
        int extra_right = 0;
        getExtraParenthesesCount(s, extra_left, extra_right);
        
        std::vector<string> result;
        removeInvalidParenthesesSub(s, 0, extra_left, extra_right, 0, result); 
        return result;
    }
    
    void getExtraParenthesesCount(const string& s, int& extra_left, int& extra_right) {
        int left_right_diff = 0;
        for (char c : s) {
            if (c == '(') {
                ++left_right_diff;   
            } else if (c == ')') {
                if (left_right_diff == 0) {
                    ++extra_right; 
                } else {
                    --left_right_diff;
                }
            }
        }
        extra_left = left_right_diff;
        return;
    }
    
    void removeInvalidParenthesesSub(string s, int index, int remaining_left, int remaining_right, int left_right_diff, std::vector<string>& result) {
        if (index == s.size()) {
            if (remaining_left == 0 && remaining_right == 0 && left_right_diff == 0) {
                result.push_back(s); 
            } 
            return;
        } 
        if (remaining_left < 0 || remaining_right < 0 || left_right_diff < 0) {
            return; 
        }
        
        if (s[index] == '(') {
            // Keep the left parentheses.
            int next = index + 1;
            int left_right_diff_copy = left_right_diff + 1;
            while (next < s.size() && s[next] == s[next - 1]) {
                ++left_right_diff_copy; 
                ++next;
            }
            removeInvalidParenthesesSub(s, next, remaining_left, remaining_right, left_right_diff_copy, result);
            // Remove the left parentheses.
            removeInvalidParenthesesSub(s.erase(index, 1), index, remaining_left - 1, remaining_right, left_right_diff, result);
        } else if (s[index] == ')') {
            // Keep the right parentheses.
            int next = index + 1;
            int left_right_diff_copy = left_right_diff - 1;
            while (next < s.size() && s[next] == s[next - 1]) {
                --left_right_diff_copy;
                ++next;
            }
            removeInvalidParenthesesSub(s, next, remaining_left, remaining_right, left_right_diff_copy, result);
            // Remove the right parentheses.
            removeInvalidParenthesesSub(s.erase(index, 1), index, remaining_left, remaining_right - 1, left_right_diff, result);
        } else {
            removeInvalidParenthesesSub(s, index + 1, remaining_left, remaining_right, left_right_diff, result);
        }
    } 
};
