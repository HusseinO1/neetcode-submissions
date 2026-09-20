class Solution {
private:
    vector<vector<int>> adj;
    vector<int> state; // 0: unvisited, 1: visiting, 2: visited
    vector<int> order;

    bool hasCycle(int course) {
        if (state[course] == 1) return true;  // Cycle detected
        if (state[course] == 2) return false; // Already processed

        state[course] = 1; // Mark as visiting

        for (int nextCourse : adj[course]) {
            if (hasCycle(nextCourse)) return true;
        }

        state[course] = 2; // Mark as fully visited
        order.push_back(course); // Add course once all dependents/prereqs are resolved

        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adj.assign(numCourses, vector<int>());
        state.assign(numCourses, 0);
        order.clear();

        // Edge direction: prerequisite -> course
        // [a, b] means b must be taken before a
        for (const auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }

        // Run DFS on every unvisited component
        for (int i = 0; i < numCourses; ++i) {
            if (state[i] == 0) {
                if (hasCycle(i)) {
                    return {}; // Impossible due to a cycle
                }
            }
        }

        // Post-order traversal places the deepest nodes first,
        // so reverse to get the correct execution order
        reverse(order.begin(), order.end());
        return order;
    }
};