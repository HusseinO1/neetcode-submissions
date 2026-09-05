class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (tokens[i] == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int sum = a + b;
                st.push(sum);
            } else if (tokens[i] == "-") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int sub = b - a;
                st.push(sub);
            } else if (tokens[i] == "*") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int prod = a * b;
                st.push(prod);
            } else if (tokens[i] == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int res = b/a;
                st.push(res);
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
