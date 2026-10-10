class Solution {
public:
    #define ll long long
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        
        int n = nums1.size();

        // priority_queue<int>pq;
        
        // ll totalMove = k1 + k2;

        // for(int i = 0; i < n; i++) {
        //     int val = abs(nums1[i]-nums2[i]);
        //     pq.push(val);
        // }

        // while(!pq.empty() && totalMove) {
        //     int val = pq.top();

        //     pq.pop();
        //     int val2 = pq.top();
        //     int diff = val-val2;
        //     val -= diff;
        //     totalMove -= diff;

        //     if(val > 0) pq.push(val);
        // }

        // ll sum = 0;
        // while(!pq.empty()) {
        //     int val = pq.top();
        //     sum += (val* 1LL* val);

        //     pq.pop();
        // }

        // return sum;


        vector<int> freq(100001, 0);
        ll totalMove = k1 + k2;

        ll sum = 0;

        for(int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);

            freq[diff]++; // increase the frequency of the difference 
        }

        for(int i = freq.size()-1; i > 0; i--) {
            if(totalMove == 0) break;
            if(freq[i] > 0) {
                if(totalMove >= freq[i]) {
                    totalMove -= freq[i];
                    freq[i-1] += freq[i];
                    freq[i] = 0;
                }
                else {
                    freq[i] -=  totalMove;
                    freq[i-1] += totalMove;
                    totalMove = 0;
                }
            }
        }

        for(int i = 0; i < freq.size(); i++) {
            sum += (1LL* i* i* freq[i]);
        }

        return sum;

    }
};