class Solution {
public:
    unordered_map<int, int>freq;
    int dp[1501][1501];
    int f(vector<int>&nums, int even, int odd, int i, int j){
        if(i > j)return 0;
        if(odd == even) return j-i+1;
        if(dp[i][j] != -1)return dp[i][j];
        int ans = 0;
        freq[nums[i]]--;
        bool c1 = (freq[nums[i]] == 0);
        ans = max(ans, f(nums, even - (c1 and ((nums[i] & 1) ? 0 : 1)), odd - (c1 and ((nums[i] & 1) ? 1 : 0)), i+1, j));
        freq[nums[i]]++;
        freq[nums[j]]--;
        bool c2 = (freq[nums[j]] == 0);
        ans = max(ans, f(nums, even - (c2 and ((nums[j] & 1) ? 0 : 1)), odd - (c2 and ((nums[j] & 1) ? 1 : 0)), i, j-1));
        freq[nums[j]]++;
        return dp[i][j] = ans;
    }
    int longestBalanced(vector<int>& nums) {
        unordered_set<int>s;
        int even = 0;
        int odd = 0;
        for(int i = 0; i < nums.size(); i++){
            s.insert(nums[i]);
            freq[nums[i]]++;
        }
        for(auto ele : s){
            if(ele & 1) odd++;
            else even++;
        }
        memset(dp, -1, sizeof dp);
        if(odd == 0 or even == 0) return 0;
        if(even == odd) return nums.size();
        return f(nums, even, odd, 0, nums.size()-1);

    }
};