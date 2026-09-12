class Solution {
public:
    #define ll long long
    void add(vector<int>& b, int i) {
        while(i < b.size()) {
            b[i]++;
            i += i & -i;
        }
    }
    int q(vector<int>& b, int i) {
        int res = 0;
        while(i > 0) {
            res += b[i];
            i -= i & -i;
        }
        return res;
    }
    long long distantSubarrays(vector<int>& nums, int goal, int k) {

        int n = nums.size();
        if(k == 0) {
            return 1LL* n * (n+1)/2;
        }
        vector<ll> pre(n+1);
        for(int i = 0; i < n; i++) {
            pre[i+1] = pre[i]+nums[i];
        }

        vector<ll> v = pre;
        sort(v.begin(), v.end());

        v.erase(unique(v.begin(), v.end()), v.end());
        vector<int> b(v.size()+1);
        int idx = lower_bound(v.begin(), v.end(), 0) - v.begin()+1;
        add(b, idx);
        ll ans = 0;
        for(int i = 1; i <= n; i++) {
            ll x = pre[i]-goal;
            int left = lower_bound(v.begin(), v.end(), x+k)-v.begin();
            int right = upper_bound(v.begin(), v.end(), x-k)-v.begin();

            ans += q(b, right);
            ans += q(b, v.size()) - q(b, left);
            int idx = lower_bound(v.begin(), v.end(), pre[i]) - v.begin() + 1;
            add(b, idx);
            
        }

        return ans;
        
        
    }
};