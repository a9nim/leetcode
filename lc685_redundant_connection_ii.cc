class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        std::vector<int> parents(edges.size() + 1, 0);
        std::vector<int> roots(edges.size() + 1, 0);
        std::vector<int> extra_parent1;
        std::vector<int> extra_parent2;
        
        // Find node with extra parents.
        for (std::vector<int>& edge : edges) {
            int parent = edge[0]; 
            int child = edge[1]; 
            if (parents[child] == 0) {
                parents[child] = parent; 
            } else {
                extra_parent1 = {parents[child], child}; 
                extra_parent2 = edge;
                // Invalidate the edge.
                edge[0] = 0;
                break;
            }
        }

        // Check for loops after extra-parent removal.
        for (const std::vector<int>& edge : edges) {
            if (edge[0] == 0) {
                continue; 
            } 
            int parent = edge[0];
            int child = edge[1];
            
            if (roots[parent] == 0) {
                roots[parent] = parent; 
            }
            if (roots[child] == 0) {
                roots[child] = child; 
            }
            int parent_root = findUnionRoot(parent, roots);
            int child_root = findUnionRoot(child, roots);
            if (parent_root == child) {
                if (extra_parent1.empty()) {
                    return edge; 
                } else {
                    return extra_parent1;
                } 
            }
            roots[child_root] = parent_root;
        }
        return extra_parent2;
    }
    
    int findUnionRoot(int node, std::vector<int>& roots) {
        while (roots[node] != node) {
            roots[node] = roots[roots[node]];
            node = roots[node];
        }
        return node;
    }
};
