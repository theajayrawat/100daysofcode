// Webpage:https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return root;

        if(root->val==p->val || root->val==q->val)
            return root;

        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);

        if(left && right)
            return root;
        else if(!left && right)
            return right;
        else if(left && !right)
            return left;
        else 
            return NULL;
    }
};