class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        
        int n = s.size();

        vector<int> start(26, -1); // start index of character
        vector<int> end(26, -1); // ending index of character

        vector<bool> isValid(26, true);

        for(int i = 0; i < n; i++) {
            if(start[s[i]-'a'] == -1) {
                start[s[i]-'a'] = i; 
            }
            end[s[i]-'a'] = i;
        }

        for(int i = 0; i < 26; i++) {
            if(start[i] == -1) continue;

            for(int c = start[i]; c <= end[i]; c++) {
                if(start[s[c]-'a'] < start[i]) {
                    isValid[i] = false;
                    break;
                }

                end[i] = max(end[i], end[s[c]-'a']);
            }
        }

        vector<string> ans;
        int lastTaken = 1e9;
        for(int i = n-1; i >= 0; i--) {
            if(!isValid[s[i]-'a']) continue;

            if(start[s[i]-'a'] == i && end[s[i]-'a'] < lastTaken) {
                ans.push_back(s.substr(i, end[s[i]-'a']-i+1));
                lastTaken = i;
            }
        }

        return ans;

    }
};