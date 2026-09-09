class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<string> currentEq;

        for(auto& token : tokens)
        {
            if(token != "+" && token != "-" && token != "*" && token != "/")
                currentEq.push(token);
            else
            {
                if(token == "+")
                {
                    int curr = stoi(currentEq.top());
                    currentEq.pop();
                    curr = stoi(currentEq.top()) + curr;
                    currentEq.pop();
                    currentEq.push(to_string(curr));
                }
                if(token == "-")
                {
                    int curr = stoi(currentEq.top());
                    currentEq.pop();
                    curr = stoi(currentEq.top()) - curr;
                    currentEq.pop();
                    currentEq.push(to_string(curr));
                }
                if(token == "*")
                {
                    int curr = stoi(currentEq.top());
                    currentEq.pop();
                    curr = stoi(currentEq.top()) * curr;
                    currentEq.pop();
                    currentEq.push(to_string(curr));
                }
                if(token == "/")
                {
                    int curr = stoi(currentEq.top());
                    currentEq.pop();
                    curr = stoi(currentEq.top()) / curr;
                    currentEq.pop();
                    currentEq.push(to_string(curr));
                }
            }
        }
        return stoi(currentEq.top());
    }
};
