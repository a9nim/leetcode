class Solution {
public:
    int minCut(string s) {
        std::vector<int> cache(s.length() + 1, -1);      
        std::vector<std::vector<int>> is_palindrome(s.length() + 1, std::vector(s.length() + 1, -1));
        return minCutRecur(s, s.length(), s.length(), cache, is_palindrome);
    }
    
    int minCutRecur(const string& s, int end_index, int length, std::vector<int>& cache, std::vector<std::vector<int>>& is_palindrome) {
        if (cache[end_index] != -1) {
            return cache[end_index]; 
        } 
        if (end_index == 0) {
            return 0; 
        } else if (isPalindrome(s, 0, end_index, is_palindrome)) {
            return 0; 
        }
        int result = std::numeric_limits<int>::max();
        for (int i = 1; i < end_index; ++i) {
            if (isPalindrome(s, i, end_index, is_palindrome) == 1) {
                result = std::min(result, minCutRecur(s, i, length, cache, is_palindrome) + 1); 
            } 
        }
        cache[end_index] = result;
        return result;
    }
    
    bool isPalindrome(const string& s, int begin_index, int end_index, std::vector<std::vector<int>>& is_palindrome) {
        int result = is_palindrome[begin_index][end_index];
        if (result != -1) {
            return result; 
        } 
        if (begin_index < end_index - 1) {
            if (s[begin_index] == s[end_index - 1]) {
                result = isPalindrome(s, begin_index + 1, end_index - 1, is_palindrome); 
            } else {
                result = 0;
            }
        } else {
            result = 1;
        }
        is_palindrome[begin_index][end_index] = result;
        return result;
    }
};
