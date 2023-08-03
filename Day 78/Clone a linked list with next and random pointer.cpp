// Link:https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    Node *copyList(Node *head)
    {
        // Write your code here
        Node *curr = head;
        while (curr)
        {
            Node *temp = curr->next;
            curr->next = new Node(curr->data);
            curr->next->next = temp;
            curr = curr->next->next;
        }

        curr = head;

        while (curr)
        {
            if (curr->arb)
                curr->next->arb = curr->arb->next;
            curr = curr->next->next;
        }

        Node *dummy = new Node(0);
        curr = head;
        Node *ans = dummy;

        while (curr)
        {
            Node *temp = curr->next->next;
            ans->next = curr->next;
            curr->next = temp;
            curr = curr->next;
            ans = ans->next;
        }

        return dummy->next;
    }
};
