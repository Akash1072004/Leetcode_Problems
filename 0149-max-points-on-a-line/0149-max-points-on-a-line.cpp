class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int n = points.size();

        if(n == 1) return 1;

        int ans = 0;

        for(int i = 0; i < n-1; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];

            for(int j = i+1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];

                // int slope = (y2-y1)/(x2-x1);
                int count = 0;
                for(int k = 0; k < n; k++) {
                    int x = points[k][0];
                    int y = points[k][1];

                    if((x2-x1)*(y-y1) == (y2-y1)*(x-x1)) count++;
                }
                ans = max(ans, count);
            }
        }

        return ans;

    }
};