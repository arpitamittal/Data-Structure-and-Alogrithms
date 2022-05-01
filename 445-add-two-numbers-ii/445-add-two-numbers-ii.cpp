/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
     
     7 <- 2 <- 4 <- 3
                    p         
 */
class Solution {
public:
    ListNode * reverse(ListNode *head)
    {
        ListNode *prev = NULL, *curr = head, *next = head->next;
        while(curr != NULL)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            if(next != NULL) next = next->next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode *n= new ListNode();
        ListNode *temp=n;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry)
        {
            int sum=0;
            if(l1!=NULL)
            {
                sum+=l1->val;              
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
             
            sum+=carry;
            carry=sum/10;
            ListNode *node= new ListNode(sum%10);
            temp->next=node;
            temp=temp->next;
        }
        return reverse(n->next);
    }
};