// Link:https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1
// Time Complexity: O(H)
// Space Complexity: O(1)

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
* /

    class Solution
{
public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    void inorder(Node *root, Node *&res, int k)
    {
        if (root == NULL)
            return;

        inorder(root->left, res, k);

        if (root->data > k && res->data > root->data)
            res = root;

        inorder(root->right, res, k);
    }
    Node *inOrderSuccessor(Node *root, Node *x)
    {
        // Your code here
        Node *res = x;
        int k = x->data;

        res->data = INT_MAX;
        inorder(root, res, k);

        if (res->data == INT_MAX)
            res->data = -1;
        return res;
    }
};