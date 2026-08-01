class Solution {
public:
    bool f(string &s, vector<vector<int>>& lcp, int n){
        for(int i = 0; i < n; i++){
            if(s[i] == s[n-1]) {
                if(lcp[i][n-1] != 1) return false;
            } 
            else {
                if(lcp[i][n-1] != 0) return false;
            }
        }
        for(int i = 0; i < n; i++){
            if(s[n-1] == s[i]) {
                if(lcp[n-1][i] != 1) return false;
            } 
            else {
                if(lcp[n-1][i] != 0) return false;
            }
        }
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < n-1; j++){
                if(s[i] == s[j]) {
                    if(lcp[i][j] != 1+lcp[i+1][j+1]) return false;
                }
                else {
                    if(lcp[i][j] != 0) return false;
                }
            }
        }
        return true;
    }
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n, '$');
        unordered_set<char> st;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(lcp[i][j] > 0) {
                    if(s[i] == '$'){
                        for(char k = 'a'; k <= 'z'; k++){
                            if(!st.count(k)) {
                                s[i] = k;
                                s[j] = k;
                                st.insert(k);
                                break;
                            }
                        }
                    }
                    else s[j] = s[i];
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(s[i] == '$') return "";
        }
        bool check = f(s, lcp, n);
        if(!check) return "";
        else return s;



    }
};