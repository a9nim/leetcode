// Solution 1: Dijkstra's algorithm
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        using DistanceNodePair = std::pair<int, int>;
        
        // Build the graph.  
        std::vector<std::vector<DistanceNodePair>> graph(n + 1, std::vector<DistanceNodePair>());
        for (const std::vector<int>& time : times) {
            int src = time[0];
            int dst = time[1];
            int dist = time[2];
            graph[src].push_back(std::make_pair(dist, dst));
        }
        
        // Initialize distances.
        std::vector<int> shortest_distance(n + 1, std::numeric_limits<int>::max());
        shortest_distance[k] = 0;
        std::priority_queue<DistanceNodePair, std::vector<DistanceNodePair>, std::greater<DistanceNodePair>> pq;
        pq.push(std::make_pair(shortest_distance[k], k));
        
        // Run Dijkstra's algorithm.
        while (!pq.empty()) {
            DistanceNodePair cur_distance_node = pq.top();
            int cur_distance = cur_distance_node.first;
            int cur_node = cur_distance_node.second;
            pq.pop();
            
            // A node might be added to `pq` multiple times because a later parent node might result in a shorter path.
            // Only process each node once, which is the time it is first poped out of `pq` and skip subsequence occurences.
            if (cur_distance > shortest_distance[cur_node]) {
                continue; 
            }
             
            for (const DistanceNodePair& distance_node_pair : graph[cur_node]) {
                 int next_distance = distance_node_pair.first; 
                 int next_node = distance_node_pair.second; 
                 int new_distance = shortest_distance[cur_node] + next_distance;
                 if (new_distance < shortest_distance[next_node]) {
                     shortest_distance[next_node] = new_distance; 
                     pq.push(std::make_pair(new_distance, next_node));
                 }
            }
        }
        
        int result = 0;
        for (int i = 1; i < shortest_distance.size(); ++i) {
            result = std::max(result, shortest_distance[i]);
        }
        if (result == std::numeric_limits<int>::max()) {
            return -1; 
        } else {
            return result;
        }
    }
};
