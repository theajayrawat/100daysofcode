// Webpage:https://leetcode.com/problems/binary-tree-level-order-traversal/description/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>v;
        if(root==NULL)
            return v;

        q.push(root);

        while(!q.empty())
        {
            int qSize=q.size();
            vector<int>s;

            while(qSize--)
            {
                TreeNode*temp=q.front();
                q.pop();
                s.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }

            v.push_back(s);
            
        }

        return v;
    }
};