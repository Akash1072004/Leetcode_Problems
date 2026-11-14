class Solution {
public:
    int countPrimes(int n) {
        if(n == 0)return 0;
        vector<int>v(n+1);
        for(int i = 0; i <= n; i++){
            v[i] = i;
        }
        for(int i = 2; i < sqrt(n); i++){
            if(v[i] != 1){
                int j = 2*i;
                while(j < n){
                    v[j] = 1;
                    j += i;
                }
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            if(v[i] != 1)count++;
        }
        return count-1;


    }
};