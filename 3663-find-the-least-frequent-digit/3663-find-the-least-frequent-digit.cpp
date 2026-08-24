class Solution {
public:
    int getLeastFrequentDigit(int n) {

        unordered_map<int, int> mp;
        while(n) {
            int ld = n % 10;
            n/= 10;
            mp[ld]++;
        }

        int mini = 1e9;
        int count = 0;
        for(auto it : mp) {
            if(mini > it.second) {
                mini = it.second;
                count = it.first;
            }
            else if(mini == it.second) {
                if(count > it.first) {
                    count = it.first;
                }
            }
        }

        return count;
        
        
    }
};