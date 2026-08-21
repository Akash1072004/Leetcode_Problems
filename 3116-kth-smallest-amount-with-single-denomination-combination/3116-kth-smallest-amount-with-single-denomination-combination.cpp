class Solution {
public:
    #define ll long long 
    ll find(vector<int>& coins, ll mid) {
        int len = coins.size();
        ll totalSubsets = (1 << len) - 1;

        ll count = 0;

        for(int mask = 1; mask <= totalSubsets; mask++) {
            
            ll setBitLCM = 1;
            for(int i = 0; i < len; i++) {
                if(mask & (1 << i)) {
                    setBitLCM = lcm(setBitLCM, (ll)coins[i]);
                }
            }

            ll noOfSetBits = __builtin_popcount(mask);
            if(noOfSetBits & 1) {
                count += (mid/setBitLCM);
            }
            else {
                count -= (mid/setBitLCM);
            }
        }

        return count;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        
        int n = coins.size();
        ll low = 0, high = 1e11;

        ll ans = 0;

        while(low <= high) {
            ll mid = low + (high-low)/2;

            ll count = find(coins, mid);

            if(count < k) {
                low = mid+1;
            }
            else {
                ans = mid;
                high = mid-1; // i have to shrink it more
            }
        }

        return ans;

    }
};