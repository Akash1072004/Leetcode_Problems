class Solution {
public:
    bool sumGame(string num) {
        
        int n = num.size();
        int leftSum = 0;
        int rightSum = 0;

        int leftQnMark = 0;
        int rightQnMark = 0;

        for(int i = 0; i < n/2; i++) {
            if(num[i] == '?') leftQnMark++;
            else leftSum += (num[i]-'0');
        }

        for(int i = n/2; i < n; i++) {
            if(num[i] == '?') rightQnMark++;
            else rightSum += (num[i]-'0');
        }

        if((leftQnMark + rightQnMark) & 1) return true;

        if(leftQnMark == rightQnMark) {
            return leftSum != rightSum;
        }

        int qnMarkDiff = leftQnMark - rightQnMark;
        int sumDiff = rightSum - leftSum;

        if(sumDiff == (qnMarkDiff/2) * 9) return false;
        return true;

    }
};