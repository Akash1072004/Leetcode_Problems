class Solution {
public:
    void change(string &ans, int end, int start, vector<int>& check){
        for(int i = end; i >= start; i--){
            if(check[i] == 1){
                ans[i] = 'b';
                return;
            }
        }
    }
    string generateString(string str1, string str2) {
        int n = str1.size(); int m = str2.size();
        int len = n + m - 1;
        string ans(len, '$');
        for(int i = 0; i < n; i++){
            if(str1[i] == 'T') {
                int idx = i; int a = 0;
                while(a < m){
                    if(ans[idx] == '$' || ans[idx] == str2[a]) ans[idx] = str2[a];
                    else return "";
                    idx++;
                    a++;
                }
            } 
        }
        vector<int> check(len, 0);
        for(int i = 0; i < len; i++){
            if(ans[i] == '$') {
                ans[i] = 'a';
                check[i]++;
            }
        }
        for(int i = 0; i < n; i++){
            if(str1[i] == 'F') {
                if(ans.substr(i, m) == str2) {
                    int idx = i + m - 1;
                    change(ans, idx, i, check);
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(str1[i] == 'T' && ans.substr(i, m) != str2) return "";
            if(str1[i] == 'F' && ans.substr(i, m) == str2) return "";
        }

        return ans;



    }
};