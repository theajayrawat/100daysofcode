// Link:https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1
// Time Complexity: O(N)
// Space Complexity: O(H)

class Solution
{
public:
    // Function to return the maximum sum of non-adjacent nodes.
    pair<int, int> solve(Node *root)
    {
        if (root == NULL)
        {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }

        pair<int, int> leftAns = solve(root->left);
        pair<int, int> rightAns = solve(root->right);

        pair<int, int> res;

        res.first = root->data + leftAns.second + rightAns.second;
        res.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);

        return res;
    }

    int getMaxSum(Node *root)
    {
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};