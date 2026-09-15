class Solution {
public:
    int n;
    int dp[2001][2001];
    bool isPal(string &s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }
    int f(string &s, int k, int i, int j) {
        if(i >= n || j >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(isPal(s, i, j)) {
            ans = max(ans, 1+f(s, k, j+1, j+k)); 
            ans = max(ans, f(s, k, i, j+1)); // increase size
            ans = max(ans, f(s, k, i+1, j+1)); // slide both the indices
        }
        ans = max(ans, f(s, k, i, j+1)); // increase size
        ans = max(ans, f(s, k, i+1, j+1)); // slide both the indices
        return dp[i][j] = ans;
    }
    int maxPalindromes(string s, int k) {
        
        n = s.size();
        if(k == 1) return n;
        memset(dp, -1, sizeof dp);
        return f(s, k, 0, k-1);

    }
};