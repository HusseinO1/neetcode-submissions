class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;

        for(auto& str : strs)
        {
            encoded_string += to_string(str.size()) + "#" + str;
        }

        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_string;
        int i = 0;
        while(i < s.size())
        {
            string num;
            while(s[i] != '#')
            {
                num += s[i];
                ++i;
            }
            decoded_string.push_back(s.substr(i + 1, stoi(num))); 
            i += 1 + stoi(num);
        }
        return decoded_string;
    }
};
