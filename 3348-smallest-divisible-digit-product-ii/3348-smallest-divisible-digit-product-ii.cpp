class Solution {
public:
    #define ll long long
    string f(ll req, int left){
        string res = "";
        for(int d = 9; d >= 2; d--){
            while(req % d == 0){
                res.push_back(d + '0');
                req /= d;
            }
        }
        while(res.size() < left){
            res.push_back('1');
        }
        reverse(res.begin(), res.end());
        return res;
    }
    string smallestNumber(string num, long long t) {
        int n = num.size();
        ll temp = t;
        vector<int> v = {2, 3, 5, 7};
        for(int p : v){
            while(temp % p == 0){
                temp /= p;
            }
        }

        if(temp != 1) return "-1";
        vector<ll> rem(n + 1);
        rem[0] = t;

        for(int i = 0; i < n; i++){
            int d = num[i] - '0';
            if(d == 0) break;
            rem[i + 1] = rem[i] / __gcd(rem[i], (ll)d);
        }

        if(rem[n] == 1) return num;
        int idx = n - 1;

        for(int i = 0; i < n; i++){
            if(num[i] == '0'){
                idx = i;
                break;
            }
        }

        for(int i = idx; i >= 0; i--){
            ll req = rem[i];
            int left = n - i - 1;

            for(int d = (num[i] - '0') + 1; d <= 9; d++){
                ll next = req / __gcd(req, (ll)d);
                string suff = f(next, left);
                if(suff.size() == left){
                    return num.substr(0, i) + char(d + '0') + suff;
                }
            }
        }
        return f(t, n + 1);
    }
};