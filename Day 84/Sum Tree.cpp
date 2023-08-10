// Link:https://practice.geeksforgeeks.org/problems/sum-tree/1
// Time Complexity: O(N)
// Space Complexity: O(H)

class Solution
{
public:
    int sum(Node *root, bool &ans)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return root->data;
        int lsum = sum(root->left, ans);
        int rsum = sum(root->right, ans);

        if (root->data != lsum + rsum)
            ans = false;

        return lsum + rsum + root->data;
    }
    bool isSumTree(Node *root)
    {
        // Your code here
        bool ans = true;
        sum(root, ans);
        return ans;
    }
};