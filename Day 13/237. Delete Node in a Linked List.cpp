// Webpage:https://leetcode.com/problems/delete-node-in-a-linked-list/

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode*del = node->next;
        node->val=node->next->val;
        node->next=node->next->next;
        delete(del);
    }
};