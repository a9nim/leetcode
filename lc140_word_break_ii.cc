class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        std::unordered_set<string> word_set(wordDict.begin(), wordDict.end());    
        std::unordered_map<string, std::vector<string>> cache;
        return wordBreakRecur(s, word_set, cache); 
    }
    
    vector<string> wordBreakRecur(const string& s, const std::unordered_set<string>& word_set, std::unordered_map<string, std::vector<string>>& cache) {
        if (cache.count(s) != 0) {
            return cache[s]; 
        } 
        std::vector<string> result;
        if (word_set.count(s) != 0) {
            result.push_back(s);
        }
        for (int i = 1; i < s.length(); ++i) {
            string word = s.substr(i);
            if (word_set.count(word) != 0) {
                for (const string& prefix : wordBreakRecur(s.substr(0, i), word_set, cache)) {
                    result.push_back(prefix + " " + word); 
                }
            }
        }
        cache[s] = result;
        return result;
    }
};
