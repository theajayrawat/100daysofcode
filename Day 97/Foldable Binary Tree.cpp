// Link:https://practice.geeksforgeeks.org/problems/foldable-binary-tree/1
// Time Complexity: O(N)
// Space Complexity: O(H)

bool help(Node *a, Node *b)
{
    if (!a && !b)
        return true;
    if (!a || !b)
        return false;

    bool c = help(a->left, b->right);
    bool d = help(a->right, b->left);

    return c && d;
}
bool IsFoldable(Node *root)
{
    // Your code goes here
    if (!root)
        return true;
    return help(root->left, root->right);
}