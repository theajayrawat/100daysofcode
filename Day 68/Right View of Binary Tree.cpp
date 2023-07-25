// Link:https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
// Time Complexity: O(N)
// Space Complexity: O(H)

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution
{
public:
    // Function to return list containing elements of right view of binary tree.
    void solve(Node *root, vector<int> &ans, int level)
    {
        if (!root)
            return;
        if (ans.size() == level)
            ans.push_back(root->data);
        solve(root->right, ans, level + 1);
        solve(root->left, ans, level + 1);
    }
    vector<int> rightView(Node *root)
    {
        // Your Code here
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};