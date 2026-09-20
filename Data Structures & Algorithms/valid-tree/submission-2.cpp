class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_set<int> visited;

    bool validTree(int n, vector<vector<int>>& edges) {
        // A tree with n nodes must have exactly n - 1 edges
        if (edges.size() != n - 1) return false;

        // Undirected graph: add both directions
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Start DFS from node 0 (parent = -1)
        if (!dfs(0, -1)) return false;

        // Ensure the entire graph is connected
        return visited.size() == n;
    }

    bool dfs(int vertex, int parent) {
        visited.insert(vertex);

        for (int neighbor : adj[vertex]) {
            // Skip the edge leading back to the immediate parent
            if (neighbor == parent) continue;

            // If already visited, a cycle exists
            if (visited.contains(neighbor)) return false;

            if (!dfs(neighbor, vertex)) return false;
        }

        return true;
    }
};