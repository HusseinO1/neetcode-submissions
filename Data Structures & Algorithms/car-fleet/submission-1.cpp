#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> xv;

        for(int i = 0; i < speed.size(); i++) {
            xv.push_back({position[i], speed[i]});
        }

        std::sort(xv.begin(), xv.end());

        stack<double> st;

        for(int i = 0; i < xv.size(); i++) {
            double timeNeeded = static_cast<double>(target - xv[i].first) / xv[i].second;
            
            while(!st.empty() && st.top() <= timeNeeded) {
                st.pop();
            }
            st.push(timeNeeded);
        }
        return st.size();
    }
};