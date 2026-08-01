class Solution {
public:
#define MOD 1000000007
#define ll long long
    int dp[1001][1001][2];
    // This Approach is best than pervous in which i put 0 and 1 by checking limit
    int f(int &zero, int &one, int z, int o, int preVal, int &limit){
        if(z > zero || o > one) return 0; 
        if(z == zero && o == one) return 1;
        if(z == zero) return (one - o <= limit && preVal == 0) ?  1 : 0; 
        if(o == one) return (zero - z <= limit && preVal == 1) ?  1 : 0;
        if(dp[z][o][preVal] != -1) return dp[z][o][preVal];
        ll ans = 0; 
        if(preVal == 1){
            // prune the repeated call in recursion
            int n = min(limit, zero - z);
            ans = (f(zero, one, z+1, o, preVal, limit)) % MOD;
            ans = (ans + f(zero, one, z+1, o, 0, limit)) % MOD;
            if(z+1+n <= zero) ans = (ans - f(zero, one, z+1+n, o, 0, limit) + MOD) % MOD;
        }
        else{
            // prune the repeated call in recursion
            int n = min(limit, one - o);
            ans = (ans + f(zero, one, z, o+1, preVal, limit)) % MOD;
            ans = (ans + f(zero, one, z, o+1, 1, limit)) % MOD;
            if(o+1+n <= one) ans = (ans - f(zero, one, z, o+1+n, 1, limit) + MOD) % MOD;
        }
        ans = ans % MOD;
        return dp[z][o][preVal] = ans;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        ll ans = 0;
        memset(dp, -1, sizeof dp);
        ans = (ans % MOD + f(zero, one, 0, 0, 0, limit) % MOD) % MOD;
        ans = (ans % MOD + f(zero, one, 0, 0, 1, limit) % MOD) % MOD;
        return ans;



    }
};