class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        
        int n = stones.size();
        int r1 = 0;
        int r2 = 0;
        for(int i = 0; i < n; i++) {
            if(stones[i] % 3 == 1) r1++;
            else if(stones[i] % 3 == 2) r2++;
        }

        if(r1 == 0 && r2 == 0) return false;
        
        int r0 = n-(r1+r2);
        // 5 8 13 25 
        if(r1 == 0) {
            if(r2 >= 3 && (r0 & 1)) return true;
            else return false;
        }
        if(r2 == 0) {
            if(r1 >= 3 && (r0 & 1)) return true;
            else return false;
        }
        else {
            if(!(r0 & 1)) {
                if(r1 > 0 && r2 > 0) return true;
                else return false;
            }
            else {
                if(abs(r1-r2) > 2) return true;
                else return false;
            }
        }

    }
};