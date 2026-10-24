class Solution {
public:
    int countMagicalPairs(string s) {

        int n = s.size();

        int ans = 0;
        // for(int i = 0; i < n; i++) {
            for(int j = 0; j < n-1; j++) {
                vector<int> a(26, 0);
                vector<int> b(26, 0);

                vector<int> lcnt(n, 0);
                vector<int> rcnt(n, 0);

                int cnt1 = 0, cnt2 = 0;

                for(int x = j; x >= 0; x--) {
                    if(a[s[x]-'a'] == 0) {
                        cnt1++;
                    }
                    a[s[x]-'a']++;
                    lcnt[cnt1]++;
                }

                for(int k = j+1; k < n; k++) {
                    if(b[s[k]-'a'] == 0) {
                        cnt2++;
                    }
                    b[s[k]-'a'] = 1;
                    rcnt[cnt2]++;
                    // if(cnt1 == cnt2) ans++;
                }

                for(int i = 1; i < n; i++) {
                    ans += (lcnt[i]* rcnt[i]);
                }
            }
        // }

        return ans;
        
    }
};