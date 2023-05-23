// Webpage:https://leetcode.com/problems/copy-list-with-random-pointer/description/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;
        Node* clonehead=NULL;
        Node* prev=NULL;
        Node* curr=head;
        
        while(curr){
            Node* temp=new Node(curr->val);
            mp[curr]=temp;
            if(!prev){
                clonehead=temp;
                prev=temp;
            }
            else{
                prev->next=temp;
                prev=temp;
            }
            
            curr=curr->next;
        }

        curr=clonehead;
        while(head){
            if(head->random)
                curr->random=mp[head->random];
            else 
                curr->random=NULL;

            head=head->next;
            curr=curr->next;
        }

        return clonehead;

    }
};
