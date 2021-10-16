class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row_count = matrix.size();
        int col_count = matrix[0].size();
        std::vector<std::vector<int>> cache(row_count, std::vector<int>(col_count));
        
        int result = 0;
        for (int i = 0; i < row_count; ++i) {
            for (int j = 0; j < col_count; ++j) {
                result = std::max(result, longestIncreasingPathRecur(i, j, row_count, col_count, matrix, cache)); 
            } 
        }
        return result;
    }
    
    int longestIncreasingPathRecur(int row, int col, int row_count, int col_count, const std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& cache) {
        int result = cache[row][col];
        if (result != 0) {
            return result;
        }
        result = 1;
        
        int cur = matrix[row][col];
        int up = (row == 0 ? 0 : matrix[row - 1][col]);
        int down = (row == row_count - 1 ? 0 : matrix[row + 1][col]);
        int left = (col == 0 ? 0 : matrix[row][col - 1]);
        int right = (col == col_count - 1 ? 0 : matrix[row][col + 1]);
        if (up > cur) {
            result = std::max(result, longestIncreasingPathRecur(row - 1, col, row_count, col_count, matrix, cache) + 1);
        } 
        if (down > cur) {
            result = std::max(result, longestIncreasingPathRecur(row + 1, col, row_count, col_count, matrix, cache) + 1);
        }
        if (left > cur) {
            result = std::max(result, longestIncreasingPathRecur(row, col - 1, row_count, col_count, matrix, cache) + 1);
        } 
        if (right > cur) {
            result = std::max(result, longestIncreasingPathRecur(row, col + 1, row_count, col_count, matrix, cache) + 1);
        }
        cache[row][col] = result;
        return result;
    }
};
