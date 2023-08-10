// Link:https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
// Time Complexity: O(N)
// Space Complexity: O(H)

class Solution
{
public:
    void traverseLeft(Node *root, vector<int> &ans)
    {
        // base case
        if ((root == NULL) || (root->left == NULL && root->right == NULL))
            return;

        ans.push_back(root->data);
        if (root->left)
            traverseLeft(root->left, ans);
        else
            traverseLeft(root->right, ans);
    }

    void traverseLeaf(Node *root, vector<int> &ans)
    {
        // base case
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
            return;
        }

        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }

    void traverseRight(Node *root, vector<int> &ans)
    {
        // base case
        if ((root == NULL) || (root->left == NULL && root->right == NULL))
            return;

        if (root->right)
            traverseRight(root->right, ans);
        else
            traverseRight(root->left, ans);

        // from back
        ans.push_back(root->data);
    }

    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
            return ans;
        }

        ans.push_back(root->data);

        // left part print/store
        traverseLeft(root->left, ans);

        // left subtree
        traverseLeaf(root, ans);

        // traverse right part
        traverseRight(root->right, ans);

        return ans;
    }
}