class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
        // if(n == 0) return 0;

        unordered_map<char, int> mp;
        int left = 0;
        int maxLen = 0;

        for(int i=0;i<n;i++){
            if(mp.count(s[i])) {
                left=max(left,mp[s[i]]+1);
            }
            
                mp[s[i]]=i;
            
            maxLen = max(maxLen, i-left+1);
        }

        

        return maxLen;

    }
};