#define ll long long
class Solution {
public:
    vector<int>v; int n; 
    unordered_map<int, unordered_map<ll, unordered_map<ll, unordered_map<ll, ll>>>> dp;
    int f(int i, ll ne, ll de, ll val, ll k){
        if(i == n and (long long)val == k) return 1;
        if(i >= n) return 0;
        if(dp.count(i) and dp[i].count(val) and dp[i][val].count(ne) and dp[i][val][ne].count(de)) return dp[i][val][ne][de];
        ll ans = 0;
        if(ne == -1 and de == -1 and val % v[i] != 0){
            ans += f(i+1, val, v[i], -1, k); // divide
            ans += f(i+1, -1, -1, val*v[i], k); // multiply
            ans += f(i+1, -1, -1, val, k); // leave
        }
        else if(ne != -1 and de != -1){
            ans += f(i+1, ne, de*v[i], -1, k); // divide
            if((ne*v[i]) % de == 0){ // multiply 
                ans += f(i+1, -1, -1, (ne*v[i]) / de, k);
            }
            else ans += f(i+1, ne*v[i], de, val, k);
            ans += f(i+1, ne, de, val, k); // leave
        }
        else {
            ans += f(i+1, -1, -1, val/v[i], k);
            ans += f(i+1, -1, -1, val*v[i], k);
            ans += f(i+1, -1, -1, val, k);
        }
        return dp[i][val][ne][de] = ans;
    }
    int countSequences(vector<int>& nums, long long k) {
        n = nums.size();
        v = nums;
        int val = 1;
        return f(0, -1, -1, 1, k);
    }
};