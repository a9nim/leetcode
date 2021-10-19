class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int boxes_size = boxes.size();
        std::vector<std::vector<std::vector<int>>> cache(boxes_size + 1, std::vector<std::vector<int>>(boxes_size + 1, std::vector<int>(boxes_size + 1)));
        return removeBoxesSub(0, boxes_size, 0, boxes, cache);
    }
    
    int removeBoxesSub(int begin, int end, int same_color, const std::vector<int>& boxes, std::vector<std::vector<std::vector<int>>>& cache) {
        if (begin == end) {
            return 0; 
        }
        int result = cache[begin][end][same_color];
        if (result != 0) {
            return result; 
        } 
        
        int input_begin = begin; 
        int input_same_color = same_color;
        for (; begin + 1 < end && boxes[begin] == boxes[begin + 1]; ++begin, ++same_color);
        result = (same_color + 1) * (same_color + 1) + removeBoxesSub(begin + 1, end, 0, boxes, cache);
        
        for (int i = begin + 1; i < end; ++i) {
            if (boxes[i] == boxes[begin]) {
                result = std::max(result, removeBoxesSub(begin + 1, i, 0, boxes, cache) + removeBoxesSub(i, end, same_color + 1, boxes, cache)); 
            } 
        } 
        cache[input_begin][end][input_same_color] = result;
        return result;
    }
};
