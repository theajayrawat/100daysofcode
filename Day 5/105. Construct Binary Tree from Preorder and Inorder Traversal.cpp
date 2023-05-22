// Webpage:https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &i, int s, int e, unordered_map<int,int>&mp)
    {
        if(i>=preorder.size()||s>e)
            return NULL;
        int element=preorder[i++];
        TreeNode*temp=new TreeNode(element);
        int mid=mp[element];
        temp->left=solve(preorder,inorder,i,s,mid-1,mp);
        temp->right=solve(preorder,inorder,i,mid+1,e,mp);

        return temp;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++)
            mp[inorder[i]]=i;

        int i=0;
        TreeNode*ans=solve(preorder,inorder,i,0,n-1,mp);
        return ans;
    }
};