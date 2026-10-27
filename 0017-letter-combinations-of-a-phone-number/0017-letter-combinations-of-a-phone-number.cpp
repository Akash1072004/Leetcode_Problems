class Solution {
public:
    vector<string> mp ={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void solve(int i, string &digits, string &s, vector<string>& ans) {
        if(i == digits.size()) {
            ans.push_back(s);
            return;
        }

        string t = mp[digits[i]-'0'];

        for(char c : t) {
            s.push_back(c);
            solve(i+1,digits,s,ans);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> ans;
        if(digits.empty()) return ans;

        string s="";
        solve(0,digits,s,ans);

        return ans;

    }
};