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

    ListNode* merge(ListNode* a,ListNode* b){
        ListNode* temp = NULL;
        if(a==NULL)return b;
        else if(b==NULL)return a;
        else if(a==NULL && b==NULL)return NULL;
        if(a->val<b->val){
            temp = a;
            a=a->next;
        }
        else {
            temp = b;
            b = b->next;
        }
        ListNode* head = temp;
        while(a!=NULL && b!=NULL){
            if(a->val<b->val){
            temp->next = a;
            a=a->next;
            temp=temp->next;
        }
        else {
            temp->next = b;
            b=b->next;
            temp=temp->next;
        }
        }
        if(a==NULL){
            while(b!=NULL){
                temp->next = b;
                b=b->next;
                temp=temp->next;
            }
        }
        else {
            while(a!=NULL){
                temp->next = a;
                a=a->next;
                temp=temp->next;
            }
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& v) {
        if(v.size()==0)return NULL;
        int i=0;
        while(i<v.size()-1){
            ListNode* a = NULL;
            ListNode* b = NULL;
            a = v[i++];
            b = v[i++];   
            ListNode* c = merge(a,b);
            v.push_back(c);
        }
        return v[v.size()-1];

    }
};