// Link:https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
// Time Complexity: O(N)
// Space Complexity: O(H)

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
public:
    // Function to return the lowest common ancestor in a Binary Tree.
    Node *lca(Node *root, int n1, int n2)
    {
        // Your code here
        if (!root)
            return NULL;

        if (n1 == root->data || n2 == root->data)
        {
            return root;
        }

        Node *a = lca(root->left, n1, n2);
        Node *b = lca(root->right, n1, n2);

        if (a != NULL && b == NULL)
        {
            return a;
        }
        else if (a == NULL && b != NULL)
        {
            return b;
        }
        else if (a != NULL && b != NULL)
        {
            return root;
        }
        else
        {
            return NULL;
        }
    }
};