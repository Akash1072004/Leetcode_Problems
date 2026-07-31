class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, false));

        // Make Blue Print
        for(int i = 0; i < n; i++) dp[i][i] = true;
        int m = 1; string ans = string(1, s[0]);
        for(int l = 2; l <= n; l++){
            for(int i = 0; i+l-1 < n; i++){
                int j = i+l-1;
                if(l == 2 && s[i] == s[j]) dp[i][j] = true;
                else {
                    if(s[i] == s[j] && dp[i+1][j-1]) dp[i][j] = true;
                }
                if(dp[i][j]) {
                    if (m < j-i+1){
                        ans = s.substr(i, j-i+1);
                        m = j-i+1;
                    } 
                }
            }
        }
        return ans;

        


    }
};