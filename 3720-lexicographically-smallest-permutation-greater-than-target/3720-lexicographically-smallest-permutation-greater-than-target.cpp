class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        
        int n = s.size();
        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++) {
            mp[s[i]]++;
        }

        string ans = "";
        for(int i = 0; i < n; i++) {
            if(mp[target[i]] > 0) {
                ans += target[i];
                mp[target[i]]--;
            }
            else {
                for(char j = 'a'; j <= 'z'; j++) {
                    if(mp[j] > 0 && j >= target[i]) {
                        ans += j;
                        mp[j]--;

                        for(int k = 'a'; k <= 'z'; k++) {
                            while(mp[k] > 0) {
                                ans += k;
                                mp[k]--;
                            }
                        }

                        return ans;
                    }
                }
                break;
            }
        }

        while(!ans.empty()) {
            int i = ans.size() - 1;
            mp[ans[i]]++;
            ans.pop_back();

            for(char c = target[i] + 1; c <= 'z'; c++) {
                if(mp[c] > 0) {
                    ans += c;
                    mp[c]--;

                    for(char x = 'a'; x <= 'z'; x++) {
                        while(mp[x] > 0) {
                            ans += x;
                            mp[x]--;
                        }
                    }
                    return ans;
                }
            }
        }

        return "";


    }
};