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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        ListNode* temp2 = head;
        if(head==NULL)return NULL;
        else if(head->next==NULL)return head;
        temp2=temp2->next;
        while(temp2!=NULL){
            if(temp->val==temp2->val) temp2=temp2->next;
            else {
                temp->next = temp2;
                temp = temp->next;
                temp2 = temp2->next;
            }
        }
        temp->next = NULL;
        return head;
    }
};