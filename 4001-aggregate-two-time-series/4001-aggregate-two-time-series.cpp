class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {

        int n = series1.size();
        int m = series2.size();

        vector<vector<int>> ans;
        int i = 0, j = 0;
        while(i < n && j < m) {
            int time = series1[i][0];
            int val = series1[i][1];

            int time2 = series2[j][0];
            int val2 = series2[j][1];

            if(time == time2) {
                int v = val+val2;
                ans.push_back({time, v});
                i++; j++;
            }
            else if(time < time2) {
                int v = val+val2;
                ans.push_back({time, v});
                i++;
            }
            else {
                int v = val+val2;
                ans.push_back({time2, v});
                j++;
            }
        }

        if(j == m) {
            while(i < n) {
                int time = series1[i][0];
                int val = series1[i][1];
                ans.push_back({time, val});
                i++;
            }
        }
        if(i == n) {
            while(j < m) {
                int time = series2[j][0];
                int val = series2[j][1];
                ans.push_back({time, val});
                j++;
            }
        }

    
        return ans;
        
    }
};