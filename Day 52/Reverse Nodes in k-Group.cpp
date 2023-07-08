// Link:https://www.codingninjas.com/studio/problems/763406?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
// Time Complexity: O(N)
// Space Complexity: O(1)

#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/
Node *reverseKGroup(Node *head, int n, int b[], int i)
{
    if (!head || !head->next || i >= n)
        return head;

    while (b[i] == 0)
        i++;
    if (i == n)
        return head;
    int counter = b[i];

    Node *prev = NULL;
    Node *curr = head;
    while (curr && counter--)
    {
        Node *ahead = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ahead;
    }

    // Recursion for rest nodes
    head->next = reverseKGroup(curr, n, b, i + 1);
    return prev;
}
Node *getListAfterReverseOperation(Node *head, int n, int b[])
{
    // Write your code here.
    return reverseKGroup(head, n, b, 0);
}
