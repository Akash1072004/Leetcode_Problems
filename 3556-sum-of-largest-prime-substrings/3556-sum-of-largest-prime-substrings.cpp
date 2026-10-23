class Solution {
public:
    #define ll long long
    bool isPrime(ll num) {
        if(num < 2) return false;

        for(ll i = 2; i* i <= num; i++) {
            if(num % i == 0) return false;
        }

        return true;
    }

    long long sumOfLargestPrimes(string s) {
        
        set<ll> st;
        int n = s.size();

        for(int i = 0; i < n; i++) {
            ll num = 0;
            for(int j = i; j < n; j++) {
                num = num* 10 + (s[j] - '0');
                if(isPrime(num)) {
                    st.insert(num);
                }
            }
        }

        ll ans = 0;
        int count = 0;

        vector<ll> v(st.begin(), st.end());
        for(int i = v.size()-1; i >= 0 && count < 3; i--) {
            ans += v[i];
            count++;
        }

        return ans;

    }
};