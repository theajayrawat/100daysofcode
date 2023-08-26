// Link:https://practice.geeksforgeeks.org/problems/e841e10213ddf839d51c2909f1808632a19ae0bf/1
// Time Complexity: O(N)
// Space Complexity: O(H)

class Solution
{
public:
    Node *search(Node *root, int target, int &s)
    {
        if (root == NULL or root->data == target)
            return root;
        s += root->data;
        if (target < root->data)
            return search(root->left, target, s);
        else
            return search(root->right, target, s);
    }

    void solve(Node *root, int curr, int &ans)
    {
        if (root->left == NULL && root->right == NULL)
        {
            curr += root->data;
            ans = min(curr, ans);
            return;
        }
        if (root->left)
            solve(root->left, curr + root->data, ans);
        if (root->right)
            solve(root->right, curr + root->data, ans);
    }

    int maxDifferenceBST(Node *root, int target)
    {
        // Code here
        int rootToTarget = 0, targetToLeaf = INT_MAX;
        Node *targetNode = search(root, target, rootToTarget);

        if (targetNode == NULL)
            return -1;

        solve(targetNode, 0, targetToLeaf);
        targetToLeaf -= target;
        return rootToTarget - targetToLeaf;
    }
};