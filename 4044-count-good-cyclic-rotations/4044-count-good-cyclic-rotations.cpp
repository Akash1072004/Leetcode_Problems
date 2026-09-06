class Solution {
public:
    #define ll long long
    int countGoodRotations(vector<int>& nums) {
        
        int n = nums.size();
        ll sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        } 

        vector<int> v(2*n, 0);
        for(int i = 0; i < n; i++) {
            v[i] = nums[i];
            v[i+n] = nums[i];
        }

        vector<ll> pre(2*n, 0);
        pre[0] = nums[0];
        for(int i = 1; i < 2*n; i++) {
            pre[i] = pre[i-1]+v[i];
        }
        int len = n/2;
        int i = 0, j = len-1;
        int count = 0;
        int ans = 0;
        while(count != n) {
            if(i > 0) {
                if(pre[j]-pre[i-1] > sum-(pre[j]-pre[i-1])) ans++;
            }
            else if(pre[j] > sum-pre[j]) ans++;
            i++, j++;
            count++;
        }
        return ans;

    }
};