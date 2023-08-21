// Link:https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution {
  public:
    int isCount(struct Node* tree){
        if(!tree)
            return 0;
        
        return 1+ isCount(tree->left)+ isCount(tree->right);
    }
    bool isCBT(struct Node* tree, int i, int nodes){
       if(!tree)return true;
        if(i>=nodes)return false;
       return isCBT(tree->left,2*i+1,nodes) && isCBT(tree->right,2*i+2,nodes);

    }
    bool isMaxHeap(struct Node* tree){
       if(!tree)
            return true;
            
        bool a=isMaxHeap(tree->left);
        bool b=isMaxHeap(tree->right);
        
        
        int left=tree->left==NULL?0:tree->left->data;
        int right=tree->right==NULL?0:tree->right->data;
        if(tree->data>left && tree->data>right  && a && b)
            return true;
        
     
        return false; 
    }
    bool isHeap(struct Node* tree) {
        // code here
        int count=isCount(tree);
        if(isCBT(tree,0,count) && isMaxHeap(tree) )
            return true;
            
        return false;
        
        
    }
};