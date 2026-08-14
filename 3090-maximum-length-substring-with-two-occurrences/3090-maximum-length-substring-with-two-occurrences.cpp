class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int count = 0;
            unordered_map<char, int> mp;
            for(int j = i; j < n; j++) {
                mp[s[j]]++;
                bool b = true;
                for(auto it : mp) {
                    if(it.second > 2) {
                        b = false;
                        break;
                    }
                }

                if(b) ans = max(ans, j-i+1);
                
            }
        }

        return ans;

    }
};