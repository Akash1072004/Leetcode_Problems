class Solution {
public:
    vector<string> ans;
    bool valid(string temp) {
        stack<char> st;
        for(int i = 0; i < temp.size(); i++) {
            if(temp[i] == '(') st.push(temp[i]);
            else {
                if(st.empty()) return false;
                st.pop();
            }
        }

        return st.empty();
    }
    void f(string &s, string &t, int n, int i, int j, string temp) {
        if(i == n && j == n) {
            if(valid(temp)) ans.push_back(temp);
            return;
        }
        if(i < n) f(s, t, n, i+1, j, temp + s[i]); // take
        if(j < n) f(s, t, n, i, j+1, temp + t[j]); // skip 
    }

    vector<string> generateParenthesis(int n) {
        
        string s = "";
        string t = "";
        for(int i = 0; i < n; i++) {
            s += '(';
            t += ')';
        }

        f(s, t, n, 0, 0, "");

        return ans;

    }
};