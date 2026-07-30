class Solution {
public:
    string smallestPalindrome(string s) {
        
        int n = s.size();
        string left = "";
        string right = "";
        string mid = "";
        vector<int> v(26, 0);

        for(int i = 0; i < n; i++) {
            v[s[i]-'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if(v[i] == 0) continue;
            int a = v[i];
            if(a & 1) {
                int b = a/2;
                while(b--) {
                    left += char(i+'a');
                    right += char(i + 'a');
                }
                mid += char(i+'a');
            }
            else {
                int b = a/2;
                while(b--) {
                    left += char(i+'a');
                    right += char(i + 'a');
                }
            }
        }
        reverse(right.begin(), right.end());

        string ans = "";
        ans = left+mid+right;
        return ans;

    }
};