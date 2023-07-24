// Link:https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {

        // Add code here
        Node *zero = new Node(-1);
        Node *one = new Node(-1);
        Node *two = new Node(-1);
        Node *zeroHead = zero;
        Node *oneHead = one;
        Node *twoHead = two;

        while (head)
        {
            int val = head->data;
            if (val == 0)
            {
                zero->next = new Node(val);
                zero = zero->next;
            }
            else if (val == 1)
            {
                one->next = new Node(val);
                one = one->next;
            }
            else
            {
                two->next = new Node(val);
                two = two->next;
            }
            head = head->next;
        }

        if (oneHead->next)
        {
            zero->next = oneHead->next;
            one->next = twoHead->next;
        }
        else
        {
            zero->next = twoHead->next;
        }
        return zeroHead->next;
    }
};
