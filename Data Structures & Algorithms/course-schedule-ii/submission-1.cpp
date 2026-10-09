class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& p : prerequisites) adj[p[0]].push_back(p[1]);

        vector<int> state(numCourses, 0);

        vector<int> ans;

        for (int i = 0; i < numCourses; ++i)
            if (!dfs(i, adj, state, ans)) return {};


        return ans;
    }

private:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state, vector<int>& ans) {
        if (state[node] == 1) return false;
        if (state[node] == 2) return true;

        state[node] = 1;
        for (int next : adj[node])
            if (!dfs(next, adj, state, ans)) return false;
        state[node] = 2;
        ans.push_back(node);
        return true;
    }
};