class Solution {
public:
    bool isValid(string s) {
        stack<char> seen;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                seen.push(c);
            } else {
                // Check if stack is empty before inspecting the top
                if (seen.empty()) {
                    return false;
                }

                if (c == '}' && seen.top() != '{') return false;
                if (c == ')' && seen.top() != '(') return false;
                if (c == ']' && seen.top() != '[') return false;

                seen.pop();
            }
        }

        // Must be empty to ensure every bracket was closed
        return seen.empty();
    }
};