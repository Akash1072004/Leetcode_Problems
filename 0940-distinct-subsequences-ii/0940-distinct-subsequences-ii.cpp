class Solution {
public:
    long long mod = 1e9 + 7;
   
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int>v(26,0);
        long long ans = 0;
        for(int i = 0;i<n;i++){
            long long old = ans;
            long long newsub = (old + 1 - v[s[i]-'a'] + mod)%mod;
            ans = (ans + newsub)%mod;
            v[s[i]-'a'] = (v[s[i]-'a'] + newsub)%mod;
        }
        return ans;
    }
};