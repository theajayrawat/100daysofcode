// Webpage:https://leetcode.com/problems/kth-smallest-element-in-a-bst/

class Solution {
public:
    void inorder(TreeNode* root,int &ans, int &k)
    {
        if(!root)
            return;
        
        inorder(root->left,ans,k);
        k--;
        if(k==0)
        {
            ans=root->val;
            return;
        }
        inorder(root->right,ans,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        inorder(root,ans,k);
        return ans;
    }
};