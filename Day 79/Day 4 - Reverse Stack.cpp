// Link:https://practice.geeksforgeeks.org/problems/reverse-a-stack/1
// Space Complexity: O(N)
// Time Complexity: O(N)

class Solution
{
public:
    void help(stack<int> &st, int val)
    {
        if (st.empty())
        {
            st.push(val);
            return;
        }

        int x = st.top();
        st.pop();
        help(st, val);

        st.push(x);
    }
    void Reverse(stack<int> &st)
    {

        if (st.empty())
            return;

        int val = st.top();
        st.pop();
        Reverse(st);

        help(st, val);
    }
};