class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
        unordered_set<int> s;
        for(auto it : nums) {
            s.insert(it);
        }

        for(int i = 1; i <= 1000; i++) {
            if(!s.count(i) && i % k == 0) return i;
        }

        return -1;

    }
};