class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return isPalindrome(left, right - 1, s) || isPalindrome(left + 1, right, s); 
            }
            ++left;
            --right;
        }
        return true;
    }
    
    bool isPalindrome(int begin, int end, const string& s) {
        if (begin >= end) {
            return true; 
        } 
        int left = begin;
        int right = end;
        while (left < right) {
            if (s[left] != s[right]) {
                return false; 
            }
            ++left;
            --right;
        }
        return true;
    }
};
