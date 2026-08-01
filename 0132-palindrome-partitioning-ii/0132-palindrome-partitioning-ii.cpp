class Solution {
public:
    int dp[2001];
    bool isPalindrome(string &s, int i, int j){
        while(i <= j){
            if(s[i] != s[j]) return false;
            else {
                i++; j--;
            }
        }
        return true;
    }
    int f(string &s, int i, int n){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 1e9;
        for(int j = i; j < n; j++){
            if(isPalindrome(s, i, j)){
                ans = min(ans, 1+f(s, j+1, n));
            }
        }
        return dp[i] = ans;
    }
    int minCut(string s) {
        int n = s.size();
        memset(dp, -1, sizeof dp);
        return f(s, 0, n) - 1;
    }
};