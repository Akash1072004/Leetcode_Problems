class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL)return NULL;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        string a = "", b = "";

        while(t1){
            a = char(t1->val + '0') + a; // store digits in reverse
            t1 = t1->next;
        }
        while(t2){
            b = char(t2->val + '0') + b;
            t2 = t2->next;
        }

        // add the strings
        string res = "";
        int carry = 0, i = a.size()-1, j = b.size()-1;
        while(i >= 0 || j >= 0 || carry){
            int sum = carry;
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';
            carry = sum / 10;
            res += char(sum % 10 + '0');
        }

        reverse(res.begin(), res.end());

        ListNode* head = new ListNode(-1);
        ListNode* newhead = head;
        for(int k = res.size()-1; k >= 0; k--){
            head->next = new ListNode(res[k] - '0');
            head = head->next;
        }
        return newhead->next;
    }
};
