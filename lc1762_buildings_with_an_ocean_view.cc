class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        std::vector<int> result;
        int max = std::numeric_limits<int>::min();
        for (int i = heights.size() - 1; i >= 0; --i) {
            int height = heights[i];
            if (height > max) {
                result.push_back(i); 
                max = height;
            }
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};
