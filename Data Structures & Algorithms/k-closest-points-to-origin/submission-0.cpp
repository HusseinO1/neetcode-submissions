class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> q;
        vector<vector<int>> ans;
        
        for(int i = 0; i < points.size(); ++i)
        {
            int dist = calcDistanceSquared(points[i]);
            
            q.push({dist, points[i]});

            if(q.size() > k)
            {
                q.pop();
            }
        }

        while(!q.empty())
        {
            ans.push_back(q.top().second);
            q.pop();
        }

        return ans;
    }
private:
    int calcDistanceSquared(vector<int>& point)
    {
        return (point[0] * point[0]) + (point[1] * point[1]);
    }
};