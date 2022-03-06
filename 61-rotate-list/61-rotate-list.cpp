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
        if(!head) return NULL;
        int len=0;
        ListNode *current=head , *prev=NULL;
        while(current!=NULL)
        {
            len++;
            prev=current;
            current=current->next;
        }
        k=k % len;
        if(len<=1 || k==0) return head;
        current=head;
        for(int i=0;i<len-k-1;i++)   current=current->next;
        ListNode *temp=current->next;
        current->next =NULL;
        prev->next=head;
        head=temp;
        return head;
    }
};
//    1 2 3 4 5 
   // 5 1 2 3 4
   // 4 5 1 2 3
   // 3 4 5 1 2

//  1 2 3 
//  4 5