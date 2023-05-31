// Webpage:https://leetcode.com/problems/odd-even-linked-list/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) 
            return head;
        
        ListNode*odd=head;
        ListNode*even=head->next;
        ListNode*evenHead=even;

        while(even&&even->next)
        {
            odd->next=even->next;
            even->next=odd->next->next;
            odd=odd->next;
            even=even->next;
        }

        odd->next=evenHead;
        return head;
    }
};