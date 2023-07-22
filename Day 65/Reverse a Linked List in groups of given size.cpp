// Link:https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
// Time Complexity: O(N)
// Sapce Complexity: O(1)

class Solution
{
public:
    struct node *reverse(struct node *head, int k)
    {
        // Complete this method
        struct node *prev = NULL;
        struct node *curr = head;
        int cnt = k;
        while (cnt-- && curr)
        {
            struct node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        if (curr)
            head->next = reverse(curr, k);
        return prev;
    }
};

