class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string n_str = std::to_string(n);
        int digits_size = digits.size();
        int result = 0;
        for (int i = 1; i < n_str.length(); ++i) {
            result += pow(digits_size, n_str.length() - i);
        }
        
        for (int i = 0; i < n_str.length(); ++i) {
            bool has_prefix = false;
            for (const string& digit : digits) {
                if (digit[0] < n_str[i]) {
                    result += pow(digits_size, n_str.length() - i - 1); 
                } else if (digit[0] > n_str[i]) {
                    return result; 
                } else {
                    has_prefix = true;
                    break;
                }
            } 
            if (!has_prefix) {
                return result; 
            }
        }
        return result + 1;
    }
};
