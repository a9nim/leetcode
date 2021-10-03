class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        std::vector<int> roots(edges.size() + 1, 0);
        std::vector<int> union_size(edges.size() + 1, 1);
        
        for (const std::vector<int>& edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            if (roots[node1] == 0) {
                roots[node1] = node1;
            }
            if (roots[node2] == 0) {
                roots[node2] = node2; 
            }
            int node1_root = findUnionRoot(node1, roots);
            int node2_root = findUnionRoot(node2, roots);
            if (node1_root == node2_root) {
                return edge;
            }
            if (union_size[node2_root] > union_size[node1_root]) {
                roots[node1_root] = node2_root;
            } else {
                roots[node2_root] = node1_root;
            }
        }
        return std::vector<int>();
    }
    
    int findUnionRoot(int node, std::vector<int>& roots) {
        while (roots[node] != node) {
            roots[node] = roots[roots[node]];
            node = roots[node]; 
        } 
        return node;
    }
};
