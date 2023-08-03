// Link:https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
    public:
    void flatten(Node *root)
    {
        //code here
        Node*curr=root;
        
        while(curr){
            if(curr->left){
                
            Node *pred = curr->left;
                while(pred->right)
                    pred = pred->right;
                
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            
            curr=curr->right;
        }
        
    
    }
};

