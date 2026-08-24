class Solution {
public:
    int score(vector<string>& cards, char x) {

        vector<int> a(10), b(10);
        int same = 0;
        for(auto it : cards) {
            if(it[0] != x && it[1] != x) {
                continue;
            }
            if(it[0] == x && it[1] == x) {
                same++;
            }
            else if(it[0] == x) {
                a[it[1]-'a']++;
            }
            else {
                b[it[0]-'a']++;
            }
        }

        int ans = 0;
        int sum1 = 0, maxi1 = 0;
        for(auto it : a) {
            sum1 += it;
            maxi1 = max(maxi1, it);
        }

        int p1 = min(sum1/2, sum1-maxi1);
        ans += p1;

        int r1 =  sum1 - 2*p1;

        int sum2 = 0, maxi2 = 0;
        for(auto it : b) {
            sum2 += it;
            maxi2 = max(maxi2, it);
        }

        int p2 = min(sum2/2, sum2-maxi2);
        ans += p2;

        int r2 = sum2 - 2* p2;

        int use = min(same, r1+r2);
        ans += use;
        same -= use;
        // ans += same/2;

        int pair = p1+p2;
        int breakPair = min(pair, same/2);

        ans -= breakPair;
        ans += 2* breakPair;
        return ans;
        
    }
};