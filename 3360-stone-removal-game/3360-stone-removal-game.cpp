class Solution {
public:
    bool canAliceWin(int n) {
        
        if(n < 10) return false;

        int a = 10;
        int turn = 0;

        while(a > 0) {
            turn++;
            n -= a;
            a--;
            if(n < a) return turn & 1;
        }

        return turn & 1;

    }
};