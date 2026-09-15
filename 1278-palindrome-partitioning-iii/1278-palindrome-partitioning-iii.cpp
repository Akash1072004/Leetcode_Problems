class Solution {
public:
    int dp[101][101][101];
    int changeChar(string &s, int i, int j) {
        int count = 0;
        while(i < j) {
            if(s[i] != s[j]) count++;
            i++, j--;
        }
        return count;
    }
    int f(string &s, int k, int i, int j) {
        if(k == 0) {
            if(i == s.size()) return 0;
            else return 1e9;
        }
        if(i >= s.size() || j >= s.size()) return 1e9;
        if (s.size() - i < k) return 1e9;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        int ans = 1e9;
        ans = min(ans, f(s, k, i, j+1));
        ans = min(ans, changeChar(s, i, j) + f(s, k-1, j+1, j+1));
        return dp[i][j][k] = ans;
    }
    int palindromePartition(string s, int k) {
        
        int n = s.size();
        if(k == n) return 0;
        memset(dp, -1, sizeof dp);
        return f(s, k, 0, 0);

    }
};