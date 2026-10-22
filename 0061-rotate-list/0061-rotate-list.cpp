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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* temp2 = head;
        ListNode* temp3 = head;
        int size = 0;
        if(head==NULL)return NULL;
        else if(head->next==NULL)return head;
        else if(k==0)return head;

        while(temp!=NULL){
            if(temp2->next!=NULL)temp2=temp2->next;
            size++;
            temp=temp->next;
        }
        if(k>=size)k=k%size;
        temp2->next = temp3;
        temp=head;
        int l=size-k;
        for(int i=1;i<l;i++){
            temp=temp->next;
        }
        head = temp->next;
        temp->next = NULL;
        return head;

    }
};