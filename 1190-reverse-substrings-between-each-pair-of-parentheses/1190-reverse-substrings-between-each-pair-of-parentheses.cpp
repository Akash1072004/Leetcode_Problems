class Solution {
public:
    string reverseParentheses(string s) {
        
        int n = s.size();
        vector<int> index;
        int len = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                index.push_back(i);
                s[i] = '*';
            }
            else if(s[i] == ')') {
                s[i] = '*';
                reverse(s.begin()+index.back(), s.begin()+i); // reverse the part of a string 
                index.pop_back();
            }
        }

        string ans = "";

        for(int i = 0; i < n; i++) {
            if(s[i] == '*') continue;
            ans += s[i];
        }
        
        return ans;

    }
};