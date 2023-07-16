// Link:https://practice.geeksforgeeks.org/problems/queue-reversal/1
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        // add code herer
        stack<int>st;
        while(!q.empty()){
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        
        return q;
    }
};

