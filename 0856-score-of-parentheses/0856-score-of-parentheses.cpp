class Solution {
public:
    int scoreOfParentheses(string s) {
        
        int n = s.size();
        // (()(()))

        int i = 0;
        int depth = 0;
        int score = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                depth++;
            }
            else {
                if(s[i-1] == '(') {
                    score += (1 << (depth-1)); 
                    depth--;
                }
                else depth--;
            }
        }

        return score;
    }
};