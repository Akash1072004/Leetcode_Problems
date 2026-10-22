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
    ListNode* partition(ListNode* head, int x) {
       ListNode* c = new ListNode(-1);
       ListNode* d = new ListNode(-1);
       if(head==NULL)return NULL;
       else if(head->next==NULL)return head;
       ListNode* temp = c;
       ListNode* temp1 = head;
       ListNode* t = d;
       while(temp1!=NULL){
        if(temp1->val<x){
            temp->next=temp1;
            temp1=temp1->next;
            temp=temp->next;
        }else if(temp1->val>=x){
             t->next=temp1;
            temp1=temp1->next;
            t=t->next;
        }
        else temp1=temp1->next;
       }
    //    temp1 = head;
    //    while(temp1!=NULL){
    //     if(temp1->val>=x){
    //         temp->next=temp1;
    //         temp1=temp1->next;
    //         temp=temp->next;
    //     }
    //     else temp1=temp1->next;
    //    }

       temp->next = d->next;
       t->next = NULL;
       return c->next;
        
    }
};