class Solution {
public:
    int check(vector<int> block, vector<int> v) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < v.size(); j++) {
                if (block[i] == v[j])
                    return 1;
            }
        }
        return 0;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m = reservedSeats.size();
        map<int, vector<int>> mp;
        for (int i = 0; i < m; i++) {
            mp[reservedSeats[i][0]].push_back(reservedSeats[i][1]);
        }
        vector<int> b1 = {2, 3, 4, 5};
        vector<int> b2 = {4, 5, 6, 7};
        vector<int> b3 = {6, 7, 8, 9};
        long long ans = 0;
        long long count = mp.size();
        ans += (n - count)*2;
        for (auto it : mp) {
            if (check(b1, it.second)) {
                if (check(b2, it.second)) {
                    if (!check(b3, it.second)) {
                        ans++;
                    }
                } else {
                    ans++;
                   
                }
            } else {
                ans++;
                if (!check(b3, it.second)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};