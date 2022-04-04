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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *front = head, *back = head, *curr = head;
        while(k > 1)
        {
            curr = curr -> next;
            front = front -> next;
            k--;
        }
        while(curr->next)
        {
            curr = curr -> next;
            back = back -> next;
        }
        swap(front->val, back->val);
        return head;
    }
};