// Link:https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
public:
    // Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(int price[], int n)
    {
        // Your code here
        stack<int> st;
        vector<int> ans(n);

        // finding next greater to left similar;

        for (int i = 0; i < n; i++)
        {
            while (st.size() != 0 && price[st.top()] <= price[i])
            {
                st.pop();
            }
            ans[i] = st.size() == 0 ? i + 1 : i - st.top();
            st.push(i);
        }

        return ans;
    }
};