class Solution {
public:
    int find(int i, vector<int>& parent) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i], parent);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; ++i) parent[i] = i;

        for (const auto& edge : edges) {
            int rootU = find(edge[0], parent);
            int rootV = find(edge[1], parent);

            if (rootU == rootV) {
                return edge;
            }
            parent[rootU] = rootV;
        }

        return {};
    }
};