// Webpage:https://leetcode.com/problems/validate-binary-search-tree/description/

class Solution {
public:
    bool isBST(TreeNode* root,TreeNode* maxi,TreeNode* mini)
    {   
        if(!root)
            return true;
        if (mini && root->val <= mini->val)
            return false;
        if (maxi && root->val >= maxi->val)
            return false;

        bool a=isBST(root->left,root,mini);
        bool b=isBST(root->right,maxi,root);

        return a && b;
    }

    bool isValidBST(TreeNode* root) {
        return isBST(root,NULL,NULL);
    }
};