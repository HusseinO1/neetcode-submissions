class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> st;

        for(auto& stone : stones)
        {
            st.push(stone);
        }

        while(st.size() > 1)
        {
            int stoneA = st.top(); st.pop();
            int stoneB = st.top(); st.pop();

            if(stoneA == stoneB) continue;

            if(stoneA > stoneB) st.push(stoneA - stoneB);
            else st.push(stoneB - stoneA);
        }

        if(!st.empty()) return st.top();
        else return 0;
    }
};
