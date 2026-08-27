class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        
        vector<int> v;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= 0) {
                v.push_back(nums[i]);
            }
        }
        int n = v.size();
        if(n == 0) {
            return nums;
        }
        k = k % n;

        vector<int> temp;

        for(int i = k; i < n; i++) {
            temp.push_back(v[i]);
        }

        for(int i = 0; i < k; i++) {
            temp.push_back(v[i]);
        }

        int j = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= 0) {
                nums[i] = temp[j];
                j++;
            }
        }

        return nums;
        

    }
};