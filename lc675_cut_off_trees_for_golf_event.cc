class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        std::vector<std::tuple<int, int, int>> height_y_x;
        for (int i = 0; i < forest.size(); ++i) {
            for (int j = 0; j < forest[0].size(); ++j) {
                int height = forest[i][j];
                if (height > 1) {
                    height_y_x.push_back(std::make_tuple(height, i, j));
                }
            }
        }
        std::sort(height_y_x.begin(), height_y_x.end());
        
        int prev_x = 0;
        int prev_y = 0;
        int result = 0;
        for (int i = 0; i < height_y_x.size(); ++i) {
            int cur_y = std::get<1>(height_y_x[i]);
            int cur_x = std::get<2>(height_y_x[i]);
            int step = getShortestPath(forest, prev_y, prev_x, cur_y, cur_x);
            if (step == -1) {
                return -1;
            } else {
                result += step; 
            }
            prev_y = cur_y;
            prev_x = cur_x;
        }
        return result;
    }
    
    int getShortestPath(const std::vector<std::vector<int>>& forest, int src_y, int src_x, int dest_y, int dest_x) {
        int total_y = forest.size();
        int total_x = forest[0].size();
        std::vector<std::vector<bool>> visited(total_y, std::vector(total_x, false));
        
        std::queue<std::pair<int, int>> bfs_queue;
        bfs_queue.push(std::make_pair(src_y, src_x));
        for (int step = 0; !bfs_queue.empty(); ++step) {
            int queue_size = bfs_queue.size(); 
            for (int i = 0; i < queue_size; ++i) {
                std::pair<int, int> item = bfs_queue.front();
                bfs_queue.pop();
                int item_y = item.first;
                int item_x = item.second;
                if (item_y == dest_y && item_x == dest_x) {
                    return step;
                }
                if (isValid(item_y - 1, item_x, total_y, total_x, forest, visited)) {
                    bfs_queue.push(std::make_pair(item_y - 1, item_x)); 
                    visited[item_y - 1][item_x] = true;
                } 
                if (isValid(item_y + 1, item_x, total_y, total_x, forest, visited)) {
                    bfs_queue.push(std::make_pair(item_y + 1, item_x)); 
                    visited[item_y + 1][item_x] = true;
                } 
                if (isValid(item_y, item_x - 1, total_y, total_x, forest, visited)) {
                    bfs_queue.push(std::make_pair(item_y, item_x - 1)); 
                    visited[item_y][item_x - 1] = true;
                } 
                if (isValid(item_y, item_x + 1, total_y, total_x, forest, visited)) {
                    bfs_queue.push(std::make_pair(item_y, item_x + 1)); 
                    visited[item_y][item_x + 1] = true;
                } 
            }
        }
        return -1;
    }
    
    bool isValid(int y, int x, int total_y, int total_x, const std::vector<std::vector<int>>& forest, const std::vector<std::vector<bool>>& visited) {
        if (y < 0 || y >= total_y || x < 0 || x >= total_x) {
            return false; 
        }
        if (forest[y][x] == 0) {
            return false; 
        }
        if (visited[y][x]) {
            return false;
        }
        return true;
    }
};
