class Solution {
public:
    string convert(string s, int numRows) {

        int n = s.size();

        if(numRows == 1 || numRows >= n) return s;

        vector<string> ans(numRows);

        int row = 0;
        int dir = 1;
        for(int i = 0; i < n; i++) {
            ans[row] += s[i];

            if(row == numRows - 1) {
                dir = -1;
            }
            else if(row == 0) {
                dir = 1;
            }
            row += dir;
        }

        string res = "";

        for(int i = 0; i < numRows; i++) {
            res += ans[i];
        }

        return res;


    }
};