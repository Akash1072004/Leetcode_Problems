class Solution {
public:
    // Recursive Method but give MLE in test Case 47 / 50
    string f(string &s, string &t, int i, int j){
        if(i == s.size()) return t.substr(j);
        if(j == t.size()) return s.substr(i);
        if(s[i] == t[j]) return s[i] + f(s, t, i+1, j+1);
        else {
            string s1 = s[i] + f(s, t, i+1, j);
            string s2 = t[j] + f(s, t, i, j+1);
            return (s1.size() < s2.size()) ? s1 : s2;
        }
    }
    string shortestCommonSupersequence(string s, string t) {
        // return f(s, t, 0, 0);
        int n = s.size(); int m = t.size(); 

        // Step 1: Build LCS Table 

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));  
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(s[i] == t[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        // Step 2: Reconstruct SCS

        int i = 0; int j = 0;
        string temp = "";
        while(i < n and j < m){
            if(s[i] == t[j]) {
                temp += s[i];
                i++; j++;
            }
            else {
                if(dp[i+1][j] > dp[i][j+1]){
                    temp += s[i];
                    i++;
                }
                else {
                    temp += t[j];
                    j++;
                }
            }
        }
        while(i < n) temp += s[i++];
        while(j < m) temp += t[j++];
        return temp;



    }
};