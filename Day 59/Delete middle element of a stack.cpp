// Link:https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        stack<int>stk;
        while(!s.empty()){
            stk.push(s.top());
            s.pop();
        }
        int deletingIndex=ceil((sizeOfStack+1)/2);
       
        int i=1;   
        while(!stk.empty()){
            if(i==deletingIndex){
                stk.pop();
            }else{
                 s.push(stk.top());
                 stk.pop();
            
            }
               i++;
        }
            
    }
};

