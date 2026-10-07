class Solution {
public:
    set<string> st;
    unordered_map<int, unordered_map<string, int>> dp;
    set<pair<string, int>> vis;
    bool isValid(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
            if(isalpha(s[i])) continue;
            if(s[i] == '(') count++;
            else count--;
            if(count < 0) return false;
        }
        return count == 0;
    }

    int f(string s, int i) {
        if(isValid(s)) return 0;
        if(i >= s.size()) return 1e9;
        if(dp.count(i) && dp[i].count(s)) return dp[i][s];
        if(isalpha(s[i])) return dp[i][s] = f(s, i+1);
        return dp[i][s] = min(f(s, i+1), 1 + f(s.substr(0, i) + s.substr(i+1), i));
    }

    void get_all_string(string s, int i, int minRemoval, int count) {
        if(count > minRemoval) return;
        if(vis.count({s, i})) return;
        vis.insert({s, i});
        if(isValid(s)) {
            if(count == minRemoval) st.insert(s);
            return;
        }

        if(i >= s.size()) return;

        if(isalpha(s[i])) {
            get_all_string(s, i+1, minRemoval, count);
            return;
        }
        string temp = s.substr(0, i) + s.substr(i+1);
        get_all_string(temp, i, minRemoval, count+1);
        get_all_string(s, i+1, minRemoval, count);
    }

    vector<string> removeInvalidParentheses(string s) {

        st.clear();
        int minRemoval = f(s, 0);
        if(minRemoval == 1e9) return {""};

        get_all_string(s, 0, minRemoval, 0);

        vector<string> ans;

        for(auto it : st) {
            ans.push_back(it);
        }

        return ans;
        
    }
};