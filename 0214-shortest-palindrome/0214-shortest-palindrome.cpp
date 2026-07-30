class Solution {
public:
    void computeLPS(string &temp, vector<int>& LPS) {
        int n = temp.size();

        int i = 1, length = 0;
        LPS[0] = 0;
        while(i < n) {
            if(temp[i] == temp[length]) { // After the length check the char at 'i' and at 'length' equal or not 
                length++;
                LPS[i] = length;
                i++;
            } else {
                if(length != 0) {
                    length = LPS[length-1];
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }

    string shortestPalindrome(string s) {
        
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());

        string temp = s + "#" + rev;
        vector<int> LPS(temp.size(), 0);
        computeLPS(temp, LPS);

        int longestLPSLength = LPS.back();

        string t = rev.substr(0, n-longestLPSLength);
        string ans = t+s;
        
        return ans;

    }
};