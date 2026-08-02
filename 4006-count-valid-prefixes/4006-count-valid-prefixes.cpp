class Solution {
public:
    int countValidPrefixes(string s) {

        int n = s.size();
        int one = 0, zero = 0;
        int ans = 0;
        int len = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') zero++;
            else one++;
            len++;
            if((len & 1) && abs(zero-one) == 1) ans++;
            else if(!(len & 1) && abs(zero-one) == 0) ans++;
        }
        return ans;
    }
};