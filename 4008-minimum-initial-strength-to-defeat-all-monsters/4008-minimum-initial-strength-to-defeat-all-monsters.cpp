class Solution {
public:
    #define ll long long
    static bool cmp(vector<int>& v1, vector<int>& v2) {
        if(v1[0] < v2[0]) return true;
        else if(v1[0] == v2[0]) {
            return v2[1] > v1[1];
        }
        else return false;
    }
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {

        int n = monsters.size();
        int m = boosts.size();

        ll low = 0, high = 1e18;
        ll ans = high;
        sort(boosts.begin(), boosts.end(), cmp);
        // vector<vector<ll>> v;
        // int i = 0;
        // while(i < m) {
        //     int start = boosts[i][0];
        //     int end = boosts[i][1];
        //     int val = boosts[i][2];

        //     if(i+1 < m && start == boosts[i+1][0]) {
        //         if(end < boosts[i+1][1]) {
        //             v.push_back({start, end, val+boosts[i+1][2]});
        //             v.push_back({end+1, boosts[i+1][1], boosts[i+1][2]});
        //         }
        //         else {
        //             v.push_back({start, end, val+boosts[i+1][2]});
        //         }
        //     }
        //     else if(i+1 < m && start < boosts[i+1][0]) {
        //         if(end > boosts[i+1][0] && end < boosts[i+1][1]) {
        //             v.push_back({start, end, val+boosts[i+1][2]});
        //             v.push_back({end+1, boosts[i+1][1], boosts[i+1][2]});
        //         }
        //         else if(end > boosts[i+1][0] && end == boosts[i+1][1]){
        //             v.push_back({start, end, val+boosts[i+1][2]});
        //         }
        //     }
        //     else {
        //         v.push_back({start, end, val});
        //     }
        //     i++;
        // }

        vector<ll> diff(n+1, 0);

        for(int j = 0; j < m; j++) {
            int s = boosts[j][0];
            int e = boosts[j][1];
            ll val = boosts[j][2];
            diff[s] += val;
            if(e+1 < n) diff[e+1] -= val;
        }

        vector<ll> v2(n, 0);
        v2[0] = diff[0];
        for(int j = 1; j < n; j++) {
            v2[j] = v2[j-1] + diff[j];
        }

        while(low <= high) {
            ll mid = low + (high-low)/2;

            ll a = mid;
            bool f = true;
            for(int j = 0; j < n; j++) {
                if(monsters[j] <= a+v2[j]) {
                    a -= monsters[j];
                    a = max((ll)0, a);
                }
                else {
                    f = false;
                    break;
                }
            }
            if(f) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
        
    }
};