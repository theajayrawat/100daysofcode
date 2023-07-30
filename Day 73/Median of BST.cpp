// Link:https://practice.geeksforgeeks.org/problems/median-of-bst/1
// Time Complexity: O(N)
// Space Complexity: O(H)

int countNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void inorder(Node *root, int &ind, float &ans)
{
    if (root == NULL)
        return;
    inorder(root->left, ind, ans);
    ind--;
    if (ind == 0)
    {
        ans = root->data;
        return;
    }
    inorder(root->right, ind, ans);
}

float findMedian(struct Node *root)
{

    int n = countNodes(root);
    float ans = 0;
    if (n % 2 != 0)
    {
        int ind = (n + 1) / 2;
        inorder(root, ind, ans);
        return ans;
    }
    else
    {
        int ind = n / 2;
        float ans1 = 0;
        inorder(root, ind, ans1);

        ind = (n / 2) + 1;
        float ans2 = 0;
        inorder(root, ind, ans2);
        ans = (ans1 + ans2) / 2;
        return ans;
    }
}
