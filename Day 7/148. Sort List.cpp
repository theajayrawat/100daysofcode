// Webpage:https://leetcode.com/problems/sort-list/description/

class Solution {
public:
    ListNode* merge(ListNode* list1, ListNode* list2){
        if(list1== NULL)
            return list1;
    
        if(list2 == NULL)
            return list2;

        ListNode* dummy=new ListNode(-1);
        ListNode*head=dummy;

        while(list1 && list2)
        {
            if(list1->val<list2->val)
            {
                head->next=list1;
                list1=list1->next;
            }
            else
            {
                head->next=list2;
                list2=list2->next;
            }
            head=head->next;
        }

        while(list1)
        {
            head->next=list1;
            list1=list1->next;
            head=head->next;
        }

        while(list2)
        {
            head->next=list2;
            list2=list2->next;
            head=head->next;
        }

        return dummy->next;
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast&&fast->next){
              fast=fast->next->next;
              slow=slow->next;
        }
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if( head == NULL || head -> next == NULL )
            return head;
    
        ListNode*mid=middleNode(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid -> next = NULL;

        right=sortList(right);
        left=sortList(left);

        ListNode*result=merge(left,right);

        return result;
    }
};