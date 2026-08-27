class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        
        int n = s.size();
        vector<string> smallestSubstring;
        int minLen = 1e9;
        for(int i = 0; i < n; i++) {
            int a = 0;
            for(int j = i; j < n; j++) {
                if(s[j] == '1') {
                    a++;
                }
                if(a == k) {
                    int len = j-i+1;
                    minLen = min(minLen, len);
                    break;
                }
            }
        }

        if(minLen == 1e9) {
            return "";
        }

        for(int i = 0; i < n; i++) {
            int a = 0;
            string temp = "";
            for(int j = i; j < n; j++) {
                temp += s[j];
                if(s[j] == '1') {
                    a++;
                }
                if(a == k && (j-i+1) == minLen) {
                    smallestSubstring.push_back(temp);
                    break;
                }
            }
        }

        string ans = smallestSubstring[0];
        for(auto it : smallestSubstring) {
            ans = min(ans, it);
        }

        return ans;



    }
};