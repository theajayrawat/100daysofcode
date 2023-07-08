// Link:https://www.codingninjas.com/studio/problems/1112655?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
// Time Complexity: O(N)
// Space Complexity: O(1)

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node *merge(Node *n1, Node *n2)
{
    Node *ans = new Node();
    Node *dummy = ans;
    while (n1 && n2)
    {
        if (n1->data < n2->data)
        {
            dummy->child = n1;
            n1 = n1->child;
            dummy = dummy->child;
        }
        else
        {
            dummy->child = n2;
            n2 = n2->child;
            dummy = dummy->child;
        }
    }

    if (n1)
    {
        dummy->child = n1;
    }
    else
    {
        dummy->child = n2;
    }

    return ans->child;
}
Node *flattenLinkedList(Node *head)
{
    // Write your code here
    if (!head || !head->next)
        return head;

    Node *down = head;
    Node *right = head->next;

    right = flattenLinkedList(right);
    down->next = NULL;
    Node *ans = merge(down, right);

    return ans;
}