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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL)return head;
        else if(left==right)return head;
        ListNode* templ = head;
        ListNode* tempr = head;
        ListNode* c = head;
        for(int i=1;i<left;i++){
            c=templ;
            templ=templ->next;
        }
        for(int i=1;i<right;i++){
            tempr=tempr->next;
        }
        ListNode* temp1 = templ;
        ListNode* temp2 = templ->next;
        ListNode* temp3 = NULL;
        if(templ->next==NULL)temp3 = NULL;
        else temp3 = templ->next->next;
        templ->next = tempr->next;
        if(templ!=head) c->next = tempr;
        while(temp3!=tempr->next){
            temp2->next = temp1;
            temp1 = temp2;
            temp2 = temp3;
            temp3 = temp3->next;
        }
        temp2->next = temp1;
        if(templ == head) return tempr;
        return head;

    }
};