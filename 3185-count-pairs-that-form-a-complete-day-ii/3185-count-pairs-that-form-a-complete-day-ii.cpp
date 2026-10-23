class Solution {
public:
    #define ll long long
    long long countCompleteDayPairs(vector<int>& hours) {
        
        vector<ll> mp(24, 0);
        ll ans = 0;

        for(int i = 0; i < hours.size(); i++) {
            int rem = hours[i] % 24;
            ans += mp[(24 - rem) % 24];
            mp[rem]++;
        }

        return ans;

        

    }
};