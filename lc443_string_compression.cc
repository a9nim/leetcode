class Solution {
public:
    int compress(vector<char>& chars) {
        char last_char = chars[0];
        int last_index = 0;
        int overwrite_index = 0;
        for (int i = 1; i < chars.size(); ++i) {
            char c = chars[i];
            if (c == last_char) {
                continue; 
            }
            chars[overwrite_index++] = last_char;
            int char_count = i - last_index;
            if (char_count > 1) {
                string char_count_str = std::to_string(char_count); 
                for (char count_c : char_count_str) {
                    chars[overwrite_index++] = count_c; 
                }
            }
            last_char = c; 
            last_index = i;
        }
        chars[overwrite_index++] = last_char;
        int char_count = chars.size() - last_index;
        if (char_count > 1) {
            string char_count_str = std::to_string(char_count); 
            for (char count_c : char_count_str) {
                chars[overwrite_index++] = count_c; 
            }
        }
        return overwrite_index;
    }
};
