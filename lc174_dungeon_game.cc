class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row_count = dungeon.size();
        int col_count = dungeon[0].size();
        std::vector<std::vector<int>> cache(row_count, std::vector<int>(dungeon[0].size()));
        return calculateMinimumHPRecur(0, 0, row_count, col_count, dungeon, cache);
    }
    
    int calculateMinimumHPRecur(int row, int col, int row_count, int col_count, const std::vector<std::vector<int>>& dungeon, std::vector<std::vector<int>>& cache) {
        if (cache[row][col] != 0) {
            return cache[row][col]; 
        }
        
        int result = 0;
        if (row == row_count - 1 && col == col_count - 1) {
            result = std::max(1 - dungeon[row][col], 1); 
        } else {
            int right = (col + 1 == col_count ? std::numeric_limits<int>::max() : calculateMinimumHPRecur(row, col + 1, row_count, col_count, dungeon, cache));
            int bottom = (row + 1 == row_count ? std::numeric_limits<int>::max() : calculateMinimumHPRecur(row + 1, col, row_count, col_count, dungeon, cache));
            result = std::max(std::min(right, bottom) - dungeon[row][col], 1);
        }
        cache[row][col] = result;
        return result;
    }
};
