class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {

        int n = img1.size();
        int ans = 0;

        for (int i = -n+1; i < n; i++) {
            for (int j = -n+1; j < n; j++) {
                int count = 0;
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < n; y++) {
                        int r = x + i;
                        int c = y + j;
                        if (r >= 0 && r < n && c >= 0 && c < n) {
                            if (img1[x][y] && img2[r][c]) {
                                count++;
                            }
                        }
                    }
                }
                ans = max(ans, count);
            }
        }
        
        return ans;
    }
};