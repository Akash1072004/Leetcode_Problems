class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> v(101);
        for(int i = 0; i < n; i++) {
            v[nums[i]].push_back(i);
        }
        int ans = 0;
        for(int i = 1; i <= 100; i++) {
            if(v[i].size() != 3) continue;
            int a = v[i][0];
            int b = v[i][1];
            int c = v[i][2];
            if(b-a == c-b) ans++;
        }

        return ans;
    }
};