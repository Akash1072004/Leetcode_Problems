  class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        
        if(head == NULL || head ->next == NULL) return head;

        ListNode * a = head;
        ListNode * b = head ->next;
        ListNode* c = new ListNode(10);
        ListNode* temp = c;

        vector<int> v;

        while(a != NULL) {
            v.push_back(a->val);
            a = a->next;
        }

        // for(int i = 0; i < v.size(); i++) {
        //     cout << v[i] << " ";
        // }

        int maxi = v[v.size()-1];

        for(int i = v.size()-2; i >= 0; i--) {
            if(v[i] < maxi) v[i] = -1;
            else maxi = v[i];
        }

        for(int i = 0; i < v.size(); i++) {
            int value = v[i];
            if(value == -1) continue; // deleted elements

            ListNode* x = new ListNode(value);
            c-> next = x;
            c = c-> next;
        }

        return temp-> next;

    }
};