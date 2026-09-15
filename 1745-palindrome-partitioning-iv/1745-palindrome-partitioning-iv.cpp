class Solution {
public:
    int dp[2001][2001][4];
    bool isPal(string &s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    bool f(string &s, int k, int i, int j) {
        int n = s.size();
        if(k == 0) return i == n;
        if(i >= n || j >= n) return false;
        if(n-i < k) return false;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        if(f(s, k, i, j+1)) return dp[i][j][k] = true;
        if(isPal(s, i, j)) {
            if(f(s, k-1, j+1, j+1)) return dp[i][j][k] = true;
        }
        return dp[i][j][k] = false;
    }

    bool checkPartitioning(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return f(s, 3, 0, 0);
    }
};