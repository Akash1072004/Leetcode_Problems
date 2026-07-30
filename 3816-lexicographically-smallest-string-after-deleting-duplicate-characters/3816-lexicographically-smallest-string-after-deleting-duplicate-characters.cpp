class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        
        int n = s.size();
        vector<int> count(26, 0);
        for(int i = 0; i < n; i++) {
            count[s[i]-'a']++;
        }
        string ans = "";
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            while(!ans.empty() && ch < ans.back() && count[ans.back()-'a'] > 1) {
                count[ans.back()-'a']--;
                ans.pop_back();
            }
            
            ans += ch;
        }

        while(!ans.empty() && count[ans.back()-'a'] > 1) {
            count[ans.back()-'a']--;
            ans.pop_back();
        }

        return ans;

    }
};