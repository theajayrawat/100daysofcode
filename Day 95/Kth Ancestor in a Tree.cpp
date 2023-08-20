// Link:https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1
// Time Complexity: O(N)
// Space Complexity: O(N)

Node *solve(Node *root, int &k, int node, int &ans)
{
    if (!root)
        return root;
    if (root->data == node)
    {
        return root;
    }

    Node *l = solve(root->left, k, node, ans);
    Node *r = solve(root->right, k, node, ans);

    if (l || r)
    {
        k--;
        if (k == 0)
        {
            ans = root->data;
        }
    }

    return l == NULL ? r : l;
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    int ans = -1;
    solve(root, k, node, ans);
    return ans;
}
