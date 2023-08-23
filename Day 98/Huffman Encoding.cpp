// Link:https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1
// Time Complexity: O(N * LogN)
// Space Complexity: O(N)

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
class cmp{
    public:
    bool operator()(node *a,node *b){
        return a->data>b->data;
    }
};

class Solution
{
	public:
	void traverse(node *root,vector<string>&ans,string temp){
	    if(root->left==NULL && root->right==NULL){
	        ans.push_back(temp);
	        return ;
	    }
	    traverse(root->left,ans,temp+'0');
	    traverse(root->right,ans,temp+'1');
	}
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    priority_queue<node*,vector<node*>,cmp>pq;
		    for(int i=0;i<N;i++){
		        node *temp=new node(f[i]);
		        pq.push(temp);
		        
		    }
		    while(pq.size()>1){
		        node* left=pq.top();
		        pq.pop();
		        node *right=pq.top();
		        pq.pop();
		        node *newnode=new node(left->data+right->data);
		        newnode->left=left;
		        newnode->right=right;
		        pq.push(newnode);
		    }
		    node *root=pq.top();
		    vector<string>ans;
		    string temp;
		    traverse(root,ans,temp);
		    return ans;  
		}
};

