// Link:https://www.codingninjas.com/studio/problems/630457?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
// Time Complexity: O(N)
// Space Complexity: O(1)

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

*****************************************************************/

Node *findIntersection(Node *firstHead, Node *secondHead)
{
    // Write your code here
    Node *n1 = firstHead;
    Node *n2 = secondHead;
    while (n1 != n2)
    {
        n1 = n1 == NULL ? secondHead : n1->next;
        n2 = n2 == NULL ? firstHead : n2->next;
    }

    return n1;
}