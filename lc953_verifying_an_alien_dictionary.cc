class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int char_rank[26];
        for (int i = 0; i < order.length(); ++i) {
            char_rank[order[i] - 'a'] = i;
        }
        for (int i = 0; i < words.size() - 1; ++i) {
            const string& cur = words[i]; 
            const string& next = words[i + 1]; 
            for (int j = 0; j < cur.length(); ++j) {
                if (j >= next.length()) {
                    return false;
                }
                if (char_rank[cur[j] - 'a'] > char_rank[next[j] - 'a']) {
                    return false; 
                } else if (char_rank[cur[j] - 'a'] < char_rank[next[j] - 'a']) {
                    break; 
                }
            }
        }
        return true;
    }
};
