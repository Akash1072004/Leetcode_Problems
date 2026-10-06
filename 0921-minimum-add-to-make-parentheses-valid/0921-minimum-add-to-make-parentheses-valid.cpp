class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int n = s.size();

        int depth = 0;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') depth++;
            else {
                depth--;
            }
            if(depth < 0) {
                depth = 0;
                ans++;
            }
        }

        return abs(depth)+ans;
 
    }
};