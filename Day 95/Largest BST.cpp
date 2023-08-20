// Link:https://practice.geeksforgeeks.org/problems/largest-bst/1
// Time Complexity: O(N)
// Space Complexity: O(H)

class info{
    public:
    int mini;
    int maxi;
    int size;
    bool isBST;
    
};

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    info solve(Node* root, int &maxSize){
        if(!root){
          return {INT_MAX,INT_MIN,0,true};  
        }
        
        info l=	solve(root->left,maxSize);
    	info r=	solve(root->right,maxSize);
    	
    	info currNode;
    	
    	currNode.size=l.size+r.size+1;
        currNode.maxi=max(root->data,r.maxi);
        currNode.mini=min(l.mini,root->data);
        
        if(l.isBST && r.isBST && root->data>l.maxi && root->data<r.mini){
            currNode.isBST=true;
        }
        else  currNode.isBST=false;
        
        if(currNode.isBST){
            maxSize=max(maxSize,currNode.size);
        }
        
        return currNode;
    	
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	int maxSize=0;
    	solve(root,maxSize);
    	
    	return maxSize;
    }
};