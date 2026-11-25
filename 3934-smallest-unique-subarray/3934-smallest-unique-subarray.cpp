class Solution {
public:
    int mod = 1000000007;
    int p = 1000003;
    map<long long, vector<int>> mp;
    // bool same(vector<int>v,int idx, int j, int m){
    //     for(int i  =0;i<m;i++){
    //         if(v[idx + i] != v[j+i]){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    bool check(vector<int>& v, int n, int m) {
        mp.clear();
        long long int h1 = 0, po = 1;
        for (int i = 0; i < m; i++) {
            h1 = (h1 * p + v[i]) % mod;
            if (i != m - 1)
                po = (po * p) % mod;
        }
        mp[h1].push_back(0);
            for(int i = 1; i <= n - m; i++) {
                int f = 0;
                h1 = (h1 - v[i - 1] * po % mod + mod) % mod;
                h1 = (h1 * p + v[i + m - 1]) % mod;
                // if (mp.count(h)) {
                //     for (auto it : mp[h]) {
                //         if (same(v, it, i, m)) {
                //             f = 1;
                //             break;
                //         }
                //     }
                // }
                mp[h1].push_back(i);
            }
        for(auto it : mp){
            if(it.second.size()==1)return true;
        }
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 1 ,r = n;
        int ans = 1;
        mp.clear();
        while(l<=r){
            int mid = l + (r-l)/2;
            if(check(nums,n,mid)){
                r = mid - 1;
                ans = mid;
            }
            else l  = mid +1;
        }
        return ans;
    }
    };