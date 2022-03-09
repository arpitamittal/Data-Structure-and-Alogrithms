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
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *curr = dummy;
        
        while(curr->next && curr->next->next)
        {
            if(curr->next->val != curr->next->next->val)
                curr = curr->next;
            else
            {
                int value = curr->next->val;
                while(curr->next && curr->next->val == value)
                {
                    curr->next = curr->next->next;
                }
            }
        }
        return dummy->next;
    }
};