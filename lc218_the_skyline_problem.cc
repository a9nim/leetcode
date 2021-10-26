class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // Each element consists of {position, BEGIN/END, height}
        std::vector<std::vector<int>> positions; 
        for (const std::vector<int>& building : buildings) {
            positions.push_back({building[0], BEGIN, building[2]}); 
            positions.push_back({building[1], END, building[2]}); 
        }
        std::sort(positions.begin(), positions.end(), [](const std::vector<int>& a, const std::vector<int>& b){
             if (a[0] != b[0]) {
                 // Sort by position.
                 return a[0] < b[0];
             }
             if (a[1] != b[1]) {
                 // Process "begin" before "end".
                 return a[1] < b[1]; 
             } 
             if (a[1] == BEGIN) {
                 // For "begin", process the heightest first.
                 return a[2] > b[2];
             } else {
                 // For "end", process the lowest first. 
                 return a[2] < b[2];
             }
        });
        
        std::vector<std::vector<int>> result;
        std::multiset<int> ms;
        for (const std::vector<int>& position : positions) {
            if (position[1] == BEGIN) {
                if (ms.empty() || position[2] > *ms.rbegin()) {
                    result.push_back({position[0], position[2]}); 
                } 
                ms.insert(position[2]);
            } else {
                ms.erase(ms.find(position[2]));
                if (ms.empty() || position[2] > *ms.rbegin()) {
                    result.push_back({position[0], ms.empty() ? 0 : *ms.rbegin()}); 
                } 
            }
        }
        return result;
    }
    
    enum PositionState {
        BEGIN = 0,
        END = 1, 
    };
};
