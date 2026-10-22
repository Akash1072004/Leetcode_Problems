class Solution {
public:
    bool isPrime(int n) {
        if(n < 2) return false;
        for(int i = 2; i *i <= n; i++) {
            if(n % i == 0) return false;
        }
        return true;
    }

    int primePalindrome(int n) {

        if(n <= 2) return 2;
        if(n <= 3) return 3;
        if(n <= 5) return 5;
        if(n <= 7) return 7;
        if(n <= 11) return 11;

        for(int i = 1; i <= 100000; i++) {
            string s = to_string(i);
            string rev = s;
            reverse(rev.begin(), rev.end());
            string temp = s + rev.substr(1);
            int num = stoi(temp);

            if(num >= n && isPrime(num)) {
                return num;
            }
        }

        return -1;


    }
};