// Link:https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        // code here
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            st.push(i);
        }

        while (st.size() > 1)
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            if (M[a][b] == 1)
            {
                st.push(b);
            }
            else if (M[b][a] == 1)
            {
                st.push(a);
            }
        }

        if (st.empty())
            return -1;
        int cel = st.top();
        for (int i = 0; i < n; i++)
        {
            if (i != cel && M[i][cel] == 0)
            {
                return -1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (M[cel][i] != 0)
            {
                return -1;
            }
        }

        return cel;
    }
};
