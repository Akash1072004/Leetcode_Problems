class Solution {
public:
    #define ll long long
    long long maxPairStrength(vector<int>& nums) {

        int n = nums.size();
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                ll g = __gcd(nums[i], nums[j]);
                ll s = (1LL*nums[i]*nums[j])/(1LL* g * g);
                ans = max(ans, s);
            }
        }

        return ans;
        
    }
};