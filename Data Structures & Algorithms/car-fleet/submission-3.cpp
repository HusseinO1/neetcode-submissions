class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> car;
        car.reserve(position.size());
        for(int i = 0; i < (int)position.size(); ++i)
        {
            car.push_back({position[i], ((double)target - position[i]) / speed[i]});
        }
        sort(car.begin(), car.end());

        stack<double> fleets;

        for(int i = 0; i < (int)car.size(); ++i)
        {
            while(!fleets.empty() && fleets.top() <= car[i].second)
            {
                fleets.pop();
            }

            fleets.push(car[i].second);
        }

        return fleets.size();
    }
};
