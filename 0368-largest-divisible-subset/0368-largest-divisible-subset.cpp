class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> len(n, 1), hash(n);
        int maxi = 0; int lastIndex = 0;
        for(int i = 0; i < n; i++){
            hash[i] = i;
            for(int prev = 0; prev < i; prev++){
                if(nums[i] % nums[prev] == 0 and len[i] < len[prev]+1){
                    len[i] = 1+len[prev];
                    hash[i] = prev;
                }
            }
            if(len[i] > maxi){
                maxi = len[i];
                lastIndex = i;
            }
        }

        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        return temp;



    }
};