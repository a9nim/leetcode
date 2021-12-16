/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        std::vector<int> dimensions = binaryMatrix.dimensions();
        int row_size = dimensions[0];
        int col_size = dimensions[1];
        int row = 0;
        int col = col_size - 1;
        while (row < row_size && col >= 0) {
            if (binaryMatrix.get(row, col) == 1) {
                int begin = 0;
                int end = col;
                while (begin + 1 < end) {
                    int mid = begin + (end - begin) / 2;
                    if (binaryMatrix.get(row, mid) == 1) {
                        end = mid; 
                    } else {
                        begin = mid;
                    }
                }
                if (binaryMatrix.get(row, begin) == 0) {
                    col = begin;
                } else {
                    col = begin - 1;
                }
            } else {
                ++row;
            }
        }
        return (col == col_size - 1) ? -1 : col + 1;
    }
};
