class Solution {
public:
    int reverseDegree(string s) {
        
        int n = s.size();
        vector<int> v(26, 0);
        int a = 26;
        for(int i = 0; i < 26; i++) {
            v[i] = a;
            a--;
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            ans += (v[s[i]-'a']* (i+1));
        }

        return ans;

    }
};