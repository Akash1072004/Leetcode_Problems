class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        if(a.second < b.second) return true;
        else if(a.second == b.second) return a.first < b.first;
        else return false;
    }
    int minSwaps(vector<int>& nums) {
        
        int n = nums.size();

        vector<pair<int, int>> digitSum(n);

        for(int i = 0; i < n; i++) {
            int sum = 0;
            int val = nums[i];

            while(val) {
                sum += (val% 10);

                val /= 10;
            }

            digitSum[i] = {nums[i], sum};
        }

        // vector<int> v = nums;

        sort(digitSum.begin(), digitSum.end(), cmp);

        map<int, int> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }

        int count = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] == digitSum[i].first){
                continue;
            }
            int idx = mp[digitSum[i].first];
            mp[nums[i]] = idx;
            swap(nums[i],nums[idx]);
            count++;
        }

        return count;

    }
};