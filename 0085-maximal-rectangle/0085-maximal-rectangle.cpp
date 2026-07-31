class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> v(m, vector<int> (n));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                v[i][j] = matrix[i][j] - '0';
            }
        }

        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                v[i][j] = (v[i][j] > 0) ? v[i][j] + v[i-1][j] : 0;
            }
        }

        vector<vector<int>> ps(m, vector<int> (n));
        vector<vector<int>> ns(m, vector<int> (n));

        for(int i = 0; i < m; i++){
            stack<int> st;
            for(int j = 0; j < n; j++){
                if(st.empty()) {
                    ps[i][j] = -1;
                    st.push(j);
                }
                else {
                    while (!st.empty() and v[i][st.top()] >= v[i][j]) st.pop(); 
                    if(st.empty()) ps[i][j] = -1;
                    else ps[i][j] = st.top();
                    st.push(j);
                }
            }
        }

        for(int i = 0; i < m; i++){
            stack<int> st;
            for(int j = n-1; j >= 0; j--){
                if(st.empty()) {
                    ns[i][j] = n;
                    st.push(j);
                }
                else {
                    while (!st.empty() and v[i][st.top()] >= v[i][j]) st.pop(); 
                    if(st.empty()) ns[i][j] = n;
                    else ns[i][j] = st.top();
                    st.push(j);
                }
            }
        }

        int maxi = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                maxi = max(maxi, (abs(ps[i][j]-ns[i][j]) - 1)* v[i][j]);
            }
        }

        return maxi;










    }
};