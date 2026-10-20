class Solution {
public:
    bool isSortable(int start, int k, vector<int>& temp) {
        int end = start + k;
        int count = 0;
        for(int i = start; i < end; i++) {
            if(i+1 == end) {
                if(temp[i] > temp[start]) count++;
            }
            else if(temp[i] > temp[i+1]) {
                count++;
            }
        }

        return count <= 1;
    }

    // bool isSortable(int start, int k, vector<int>& temp) {
    //     int count = 0;
    //     int end = start + k;

    //     for(int i = start; i < end; i++) {
    //         if(temp[i] > temp[start + (i - start + 1) % k]) {
    //             count++;
    //         }
    //     }

    //     return count <= 1;
    // }

    int sortableIntegers(vector<int>& nums) {
        
        // 7 6 5  ->  6 5 7  ->  5 7 6
        int n = nums.size();

        vector<int> divisors;
        for(int i = 1; i* i <= n; i++) {
            if(n % i == 0) {
                divisors.push_back(i);

                if(i != n/i) divisors.push_back(n/i);
            }
        }

        int result = 0;

        for(int i = 0; i < divisors.size(); i++) {
            vector<int> temp = nums;
            bool valid = true;
            int k = divisors[i];
            for(int j = 0; j < n; j += k) {
                if(!isSortable(j, k, temp)) {
                    valid = false;
                    break;
                }

                if(j > 0) {
                    int prevMax = nums[j-k];
                    int curMin = nums[j];

                    for(int l = j-k; l < j; l++) {
                        prevMax = max(prevMax, nums[l]);
                    }

                    for(int l = j; l < j+k; l++) {
                        curMin = min(curMin, nums[l]);
                    }

                    if(prevMax > curMin) {
                        valid = false;
                        break;
                    }
                }
            }

            if(valid) result += k;
        }

        return result;

    }
};