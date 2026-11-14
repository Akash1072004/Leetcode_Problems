class Solution {
public:
    bool isPowerOfTwo(int n) {
        double a=n;
        while(a>0){
            if(a==1)return true;
            else a=a/2;
        }
        return false ;
    }
};