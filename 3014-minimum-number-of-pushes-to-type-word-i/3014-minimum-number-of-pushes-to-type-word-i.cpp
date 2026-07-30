class Solution {
public:
    static bool cmp(pair<char, int>& p1, pair<char, int>& p2) {
        return p1.second > p2.second;
    }
    int minimumPushes(string word) {

        int n = word.size();

        if(n <= 8) return n;
        
        unordered_map<char, int> mp;
        for(auto c : word) {
            mp[c]++;
        }

        vector<pair<char, int>> v;

        for(auto it : mp) {
            v.push_back(it);
        }

        sort(v.begin(), v.end(), cmp);

        int count = 0;
        int ans = 0;
        int b = 1;
        for(auto it : v) {
            ans += (it.second* b);
            count++;
            if(count == 8) {
                count = 0;
                b++;
            }
        }

        return ans;



    }
};