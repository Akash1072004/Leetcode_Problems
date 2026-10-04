class Solution {
public:
    bool checkValidString(string s) {
        
        int n = s.size();

        int mini = 0, maxi = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                mini++;
                maxi++;
            }
            else if(s[i] == ')') {
                mini--;
                maxi--;
            }
            else {
                mini--;
                maxi++;
            }
            if(maxi < 0) return false;

            mini = max(mini, 0);
        }

        if(mini > 0) return false;
        return true;


    }
};