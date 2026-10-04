class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
        if(n == 0) return 0;

        unordered_map<char, int> mp;
        int left = 0, right = 0;
        int maxLen = 1;

        while(right < n) {
            if(mp.count(s[right])) {
                int idx = mp[s[right]];
                maxLen = max(maxLen, right-left);
                if(idx >= left) left = idx+1;
                // mp[s[right]] = right;
            }
            mp[s[right]] = right;
            // maxLen = max(maxLen, right-left+1);
            right++;
        }

        maxLen = max(maxLen, right-left);

        return maxLen;

    }
};