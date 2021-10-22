class Solution {
public:
    int strangePrinter(string s) {
        int s_len = s.length();
        std::vector<std::vector<std::vector<int>>> cache(s_len + 1, std::vector<std::vector<int>>(s_len + 1, std::vector<int>(2)));
        return strangePrinterSub(s, 0, s_len, 0, cache);
    }
    
    int strangePrinterSub(const string& s, int begin, int end, int pending_prefix, std::vector<std::vector<std::vector<int>>>& cache) {
        if (begin == end) {
            return 0; 
        }
        int result = cache[begin][end][pending_prefix];
        if (result != 0) {
            return result;
        }
        int dedup_begin = begin;
        while (dedup_begin + 1 != end && s[dedup_begin] == s[dedup_begin + 1]) {
            ++dedup_begin;
        }
        result = 1 + strangePrinterSub(s, dedup_begin + 1, end, 0, cache);
        for (int i = dedup_begin + 1; i != end; ++i) {
            if (s[i] == s[dedup_begin]) {
                result = std::min(result, strangePrinterSub(s, dedup_begin + 1, i, 0, cache) + strangePrinterSub(s, i, end, 1, cache)); 
            } 
        }
        cache[begin][end][pending_prefix] = result;
        return result;
    }
};
