class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        
        if(sum > (9*num)) return "";

        long long result = 0;

        string number = "";

        for(int i = 9; i >= 1; i--) {
            // long long val = 0;
            while(result + i <= sum && number.size() < num) {
                number += i + '0';
                result += i;
            }

            // if(result == sum) break;

        }

        // string temp = to_string(result);
        if(number.size() < num) {
            while(number.size() != num) number += "0";
        }

        return number;

    }
};