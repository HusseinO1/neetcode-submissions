class Solution {
private:
    vector<vector<int>> adj;
    vector<int> state; // 0: unvisited, 1: visiting, 2: visited

    bool hasCycle(int course) {
        if (state[course] == 1) return true;  // Found a cycle
        if (state[course] == 2) return false; // Already verified safe

        state[course] = 1; // Mark as currently visiting
        for (int next : adj[course]) {
            if (hasCycle(next)) return true;
        }
        state[course] = 2; // Mark as fully processed

        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.assign(numCourses, vector<int>());
        state.assign(numCourses, 0);

        for (const auto& edge : prerequisites) {
            adj[edge[0]].push_back(edge[1]);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (state[i] == 0 && hasCycle(i)) {
                return false;
            }
        }

        return true;
    }
};