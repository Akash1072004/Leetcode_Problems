class Solution {
public:
    #define ll long long
    int countSpecialIntegers(vector<int>& nums) {

        int n = nums.size();
        unordered_map<ll, vector<ll>> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        } 
        int ans = 0;
        for(auto &it : mp) {
            if(it.second.size() < 3) continue;
            ll d = it.second[1]-it.second[0];
            bool f = true;
            for(int i = 2; i < it.second.size(); i++) {
                if(it.second[i] - it.second[i-1] != d) {
                    f = false;
                    break;
                }
            }
            if(f) ans++;
        }

        return ans;
    }
};