// Webpage:https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) 
            return NULL;
        queue<Node*> q;
        q.push(root);        
        while(!q.empty()) {
            int qSize=q.size();
            Node* rightNode = NULL;                    
            while(qSize--) {                
                auto cur = q.front(); 
                q.pop();            
                cur -> next = rightNode;                 
                rightNode = cur;                          
                if(cur -> right)                          
                    q.push(cur -> right);
                if(cur -> left)                 
                    q.push(cur -> left);                  
            }
        }
        return root;
    }
};