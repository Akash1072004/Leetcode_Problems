/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int a=1,b=1,c=0,d=0,e=0;
        vector<int>v(2);
        if(head==NULL || head->next == NULL || head->next->next==NULL){
            v={-1,-1};
            return v;
        }
        int size=0;
        ListNode* temp = head;
        while(temp){
            size++;
            temp=temp->next;
        }
        if(size<4){
            v={-1,-1};
            return v;
        }
        int m = INT_MAX;
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        while(temp2->next!=NULL){
            if(temp2->val<temp1->val && temp2->val<temp2->next->val)break;
            else if(temp2->val>temp1->val && temp2->val>temp2->next->val)break;
            else {
                a++;
                temp2=temp2->next;
                temp1=temp1->next;
            }
        }
        if(temp2->next==NULL){
            v = {-1,-1};
            return v;
        }
        c=a;//minimum idx
        b=a+1;
        temp2=temp2->next;
        temp1=temp1->next;
        while(temp2->next!=NULL){
            if(temp2->val<temp1->val && temp2->val<temp2->next->val){
                m=min(m,b-a);
                a=b;
                b=a+1;
                temp2=temp2->next;
                temp1=temp1->next;
            }
            else if(temp2->val>temp1->val && temp2->val>temp2->next->val){
                m=min(m,b-a);
                a=b;
                b=a+1;
                temp2=temp2->next;
                temp1=temp1->next;
            }
            else {
                temp2=temp2->next;
                temp1=temp1->next;
                b++;
            }
        }
        if(m==INT_MAX){
            v = {-1,-1};
            return v;
        }
        int m1 = a-c;
        v[0]=m;
        v[1]=m1;
        return v;

    }
};