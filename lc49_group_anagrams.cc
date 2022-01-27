class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, std::vector<string>> sorted_str_to_original_strs;
        for (const string& str : strs) {
            string str_copy = str; 
            std::sort(str_copy.begin(), str_copy.end());
            sorted_str_to_original_strs[str_copy].push_back(str);
        }
        
        std::vector<std::vector<string>> result;
        for (const auto& sorted_str_original_strs_pair : sorted_str_to_original_strs) {
            const std::vector<string>& original_strs = sorted_str_original_strs_pair.second;
            result.push_back(original_strs); 
        }
        return result;
    }
};
