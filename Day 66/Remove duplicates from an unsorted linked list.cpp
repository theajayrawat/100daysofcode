// Link:https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1
// Time Complexity: O(N)
// Sapce Complexity: O(N)

/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution
{
public:
    // Function to remove duplicates from unsorted linked list.
    Node *removeDuplicates(Node *head)
    {
        // your code goes here
        unordered_set<int> st;
        Node *dummy = new Node(-1);
        Node *temp = dummy;

        while (head)
        {

            if (st.find(head->data) != st.end())
            {
                head = head->next;
                continue;
            }

            st.insert(head->data);
            temp->next = new Node(head->data);
            temp = temp->next;
        }

        return dummy->next;
    }
};
