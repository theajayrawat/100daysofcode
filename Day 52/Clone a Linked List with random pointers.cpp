// Link:https://www.codingninjas.com/studio/problems/clone-a-linked-list-with-random-pointers_983604?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
// Time Complexity: O(N)
// Space Complexity: O(1)

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *random;
 *		Node() : data(0), next(nullptr), random(nullptr){};
 *		Node(int x) : data(x), next(nullptr), random(nullptr) {}
 *		Node(int x, Node *next, Node *random) : data(x), next(next), random(random) {}
 * };
 */

Node *cloneLL(Node *head)
{
    // Write your code here
    Node *temp = head;
    while (temp)
    {
        Node *neww = new Node(temp->data);
        neww->next = temp->next;
        temp->next = neww;
        temp = temp->next->next;
    }

    Node *itr = head;
    while (itr)
    {
        if (itr->random)
            itr->next->random = itr->random->next;
        itr = itr->next->next;
    }

    Node *dummy = new Node(0);
    itr = head;
    temp = dummy;
    Node *fast;
    while (itr != NULL)
    {
        fast = itr->next->next;
        temp->next = itr->next;
        itr->next = fast;
        temp = temp->next;
        itr = fast;
    }
    return dummy->next;
}