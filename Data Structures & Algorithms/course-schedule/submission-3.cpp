class Solution {
public:

    bool DFS(unordered_map<int, vector<int>>& m, unordered_set<int>& seen, int curr)
    {
        if(seen.contains(curr)) return false;
        if(m[curr].empty()) return true;

        seen.insert(curr);
        for(auto& c : m[curr])
        {
            if(!DFS(m, seen, c)) return false;
        }
        seen.erase(curr);
        m[curr].clear();
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> m;

        for(auto& pre : prerequisites)
        {
            m[pre[1]].push_back(pre[0]);
        }

        unordered_set<int> seen;
        
        for (int i = 0; i < numCourses; i++)
        { 
            if (!DFS(m, seen, i)) return false;
        }

        return true;
    }
};
