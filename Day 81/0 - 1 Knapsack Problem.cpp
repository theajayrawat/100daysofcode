// Link:https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
// Time Complexity: O(N*W)
// Space Complexity: O(N*W)

class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));
        for (int w = wt[0]; w <= W; w++)
        {
            if (wt[0] <= W)
                dp[0][w] = val[0];
            else
                dp[0][w] = 0;
        }

        for (int index = 1; index < n; index++)
        {
            for (int w = 0; w <= W; w++)
            {
                int include = 0;
                if (wt[index] <= w)
                    include = val[index] + dp[index - 1][w - wt[index]];

                int exclude = dp[index - 1][w];

                dp[index][w] = max(include, exclude);
            }
        }
        return dp[n - 1][W];
    }
};