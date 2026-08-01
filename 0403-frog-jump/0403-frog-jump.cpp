class Solution {
public:
    unordered_map<int,int>mp;
    int dp[2001][2001];
    bool f(vector<int> & stones, int i, int lastJump){
        if(i >= stones.size()) return false;
        if(i == stones.size()-1)return true;
        if(dp[i][lastJump] != -1) return dp[i][lastJump];
        bool ans = false;
        if(lastJump-1 > 0 and mp.count(stones[i]+(lastJump-1))){
            ans |= f(stones, mp[stones[i]+(lastJump-1)], lastJump-1);
        }
        if(mp.count(stones[i]+(lastJump))){
            ans |= f(stones, mp[stones[i]+(lastJump)], lastJump);
        }
        if(mp.count(stones[i]+(lastJump+1))){
            ans |= f(stones, mp[stones[i]+(lastJump+1)], lastJump+1);
        }
        return dp[i][lastJump] = ans;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(stones[1] != 1) return false;
        for(int i = 0; i < n; i++){
            mp[stones[i]] = i;
        }
        memset(dp, -1, sizeof dp);
        return f(stones, 1, 1);



    }
};