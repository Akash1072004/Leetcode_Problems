class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if(n == 0) return 0;
        int opening = 0; int closing = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '(') opening++;
            else closing++;
            if(opening == closing) {
                ans = max(ans, opening*2);
            }
            if(closing > opening){
                opening = closing = 0;
            }
        }
        opening = closing = 0;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == ')') closing++;
            else opening++;
            if(opening == closing){
                ans = max(ans, closing*2);
            }
            if(opening > closing){
                opening = closing = 0;
            }
        }
        return ans;



    }
};