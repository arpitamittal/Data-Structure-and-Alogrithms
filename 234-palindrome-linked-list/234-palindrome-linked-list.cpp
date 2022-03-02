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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode *previousNode=NULL,*currentNode=head,*nextNode=head->next; 
        while(currentNode!=NULL)
        {
            currentNode->next=previousNode;
            previousNode=currentNode;
            currentNode=nextNode;
            if(nextNode!=NULL) nextNode = nextNode->next;
        }
        return previousNode;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head, *fast=head;
        while(fast && fast->next && fast->next->next )
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next = reverseList(slow->next);
        ListNode *start=head, *mid=slow->next;
        while(mid)
        {
            if(start->val!=mid->val) return false;
            start=start->next;
            mid=mid->next;
        }
        reverseList(slow->next);
        return true;
    }
};