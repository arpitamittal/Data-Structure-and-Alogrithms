/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
   1 2 3 4 5 6 7 8 9 10
   n = 3   8
   10 - 3 = 7+1 = 8
   Removing nth node from last = removing size-n+1 node from begining 
   
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *curr = dummy;
        int size = 0;
        while(curr != NULL)
        {
            curr = curr->next;
            size++;
        }
        curr = dummy;
        for(int i=1; i<size-n; i++)
        {
            curr = curr->next;
        }
        curr->next = curr->next->next;
        return dummy->next;
    }
};