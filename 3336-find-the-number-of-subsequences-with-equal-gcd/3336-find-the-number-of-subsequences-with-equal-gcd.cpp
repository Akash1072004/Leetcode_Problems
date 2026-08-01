class Solution {
public:
    #define MOD 1000000007
    int n;
    int dp[201][201][201];
    int f(vector<int>& nums, int i, int gcd1, int gcd2) {
        if(i == n) {
            if(gcd1 != 0 && gcd2 != 0 && gcd1 == gcd2) return 1;
            else return 0;
        }
        if(dp[i][gcd1][gcd2] != -1) return dp[i][gcd1][gcd2];
        int ans = 0;
        ans = (ans + f(nums, i+1, gcd1, gcd2)) % MOD;
        ans = (ans + f(nums, i+1, __gcd(gcd1, nums[i]), gcd2)) % MOD;
        ans = (ans + f(nums, i+1, gcd1, __gcd(gcd2, nums[i]))) % MOD;
        return dp[i][gcd1][gcd2] = ans;
    }
    int subsequencePairCount(vector<int>& nums) {
        
        n = nums.size();
        memset(dp, -1, sizeof dp);
        return f(nums, 0, 0, 0);

    }
};