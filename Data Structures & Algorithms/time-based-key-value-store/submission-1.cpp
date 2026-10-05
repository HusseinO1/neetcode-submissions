class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> keyVal;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyVal[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(!keyVal.contains(key)) return "";

        vector<pair<string, int>>& curr = keyVal[key];

        int currSize = curr.size();

        int right = currSize - 1;

        int left = 0;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            int midTime = curr[mid].second;
            if(midTime == timestamp) return curr[mid].first;
            else if(midTime < timestamp) left = mid + 1;
            else right = mid - 1;
        }

        return right >= 0 ? curr[right].first : "";
    }
};
