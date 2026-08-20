class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> arr1, arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for(int i = 2; i < n; i++) {
            if(arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            }
            else {
                arr2.push_back(nums[i]);
            }
        }

        vector<int> result(n);
        int a = 0;
        for(int i = 0; i < arr1.size(); i++) {
            result[a] = arr1[i];
            a++;
        }
        for(int i = 0; i < arr2.size(); i++) {
            result[a] = arr2[i];
            a++;
        }

        return result;

    }
};