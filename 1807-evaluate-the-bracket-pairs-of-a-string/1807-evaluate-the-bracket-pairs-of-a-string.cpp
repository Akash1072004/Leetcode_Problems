class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        map<string, string> mp;
        for(int i = 0; i < knowledge.size(); i++) {
            mp[knowledge[i][0]] = knowledge[i][1];
        }

        string result = "";

        string temp = "";
        for(char ch : s) {
            if(ch == '(' || ch == ')') {
                if(ch == ')') {
                    if(mp.count(temp)) result += mp[temp];
                    else result += '?';
                }
                else result += temp;
                temp = "";
                continue;
            }

            temp += ch;
        }

        result += temp;

        return result;

    }
};