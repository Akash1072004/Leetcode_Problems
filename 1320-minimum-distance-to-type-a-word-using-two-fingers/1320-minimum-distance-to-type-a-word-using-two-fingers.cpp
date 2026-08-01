class Solution {
public:
    unordered_map<char, pair<int, int> > mp;
    unordered_map<int, unordered_map<char, unordered_map<char, int>>> dp;
    int f(string &s, int i, char f1, char f2) {
        if(i == s.size()) return 0;
        if(dp.count(i) && dp[i].count(f1) && dp[i][f1].count(f2)) return dp[i][f1][f2];
        int cost1 = 0, cost2 = 0;
        if(f1 == '#') cost1 = 0;
        else {
            auto c1 = mp[s[i]];
            int x1 = c1.first, y1 = c1.second;
            auto c2 = mp[f1];
            int x2 = c2.first, y2 = c2.second;
            cost1 = abs(x1-x2) + abs(y1-y2);
        }
        if(f2 == '#') cost2 = 0;
        else {
            auto c1 = mp[s[i]];
            int x1 = c1.first, y1 = c1.second;
            auto c2 = mp[f2];
            int x2 = c2.first, y2 = c2.second;
            cost2 = abs(x1-x2) + abs(y1-y2);
        }
        return dp[i][f1][f2] = min(cost1+f(s, i+1, s[i], f2), cost2+f(s, i+1, f1, s[i]));
    }
    int minimumDistance(string word) {

        int n = word.size();
        if(n == 2) return 0;

        char ch = 'A';
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 6; j++) {
                mp[ch] = {i, j};
                ch++;
            }
        }  

        return f(word, 0, '#', '#');
        
        

        
    }
};