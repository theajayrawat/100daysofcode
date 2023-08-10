// Link:https://practice.geeksforgeeks.org/problems/cutted-segments1642/1
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
public:
    // Function to find the maximum number of cuts.
    int solve(int n, vector<int> &cut, vector<int> &dp)
    {
        if (n == 0)
            return 0;
        if (n < 0)
            return INT_MIN;
        if (dp[n] != -1)
            return dp[n];

        int maxi = INT_MIN;

        for (int i = 0; i < 3; i++)
        {
            int a = solve(n - cut[i], cut, dp);
            if (a != INT_MIN)
                maxi = max(maxi, a + 1);
        }

        return dp[n] = maxi;
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // Your code here
        vector<int> cut{x, y, z};
        vector<int> dp(n + 1, -1);
        int ans = solve(n, cut, dp);
        return ans == INT_MIN ? 0 : ans;
    }
};