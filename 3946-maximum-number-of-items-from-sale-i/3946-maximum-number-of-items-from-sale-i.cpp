class Solution {
public:
    int dp[1001][1501][2];
    int f(vector<vector<int>> &v, int i, int b) {
        if(i == v.size()) return 0;
        int check = v[i][2];
        if(dp[i][b][check] != -1) return dp[i][b][check];
        int ans = 0;
            if(b >= v[i][0]) {
            if(v[i][2] == 0) {
                v[i][2] = 1;
                ans = max(ans, v[i][1] + f(v, i, b-v[i][0]));
                ans = max(ans, v[i][1] + f(v, i+1, b-v[i][0]));
                ans = max(ans, f(v, i+1, b));
                v[i][2] = 0;
            }
            else {
                ans = max(ans, 1 + f(v, i, b-v[i][0]));
                ans = max(ans, 1 + f(v, i+1, b-v[i][0]));
                ans = max(ans, f(v, i+1, b));
            }
        }
        else ans = max(ans, f(v, i+1, b));
        

        return dp[i][b][check] = ans;
    }
    int maximumSaleItems(vector<vector<int>>& v, int b) {

        int n = v.size();

        vector<vector<int>> v2(n, vector<int> (3));

        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(v[j][0] % v[i][0] == 0) {
                    count++;
                }
            }
            v2[i][0] = v[i][1]; 
            v2[i][1] = count+1; 
            v2[i][2] = 0; 
        }

        memset(dp, -1, sizeof dp);

        return f(v2, 0, b);
        
    }
};