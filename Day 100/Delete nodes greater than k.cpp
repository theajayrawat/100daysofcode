// Link: https://practice.geeksforgeeks.org/problems/delete-nodes-greater-than-k/1
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    /*The function should return the root of the modified tree*/
    Node *deleteNode(Node *root, int k)
    {
        // Your code here
        if (!root)
            return root;

        root->left = deleteNode(root->left, k);
        root->right = deleteNode(root->right, k);

        if (root->data >= k)
        {
            root->right = NULL;
            root = root->left;
        }

        return root;
    }
};