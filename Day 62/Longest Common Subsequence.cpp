// Link:https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
// Time Complexity: O(N^2)
// Space Complexity: O(N^2)

class Solution
{
public:
    // Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int ind1 = 0; ind1 <= n; ind1++)
        {
            for (int ind2 = 0; ind2 <= m; ind2++)
            {

                if (ind1 == 0 || ind2 == 0)
                    dp[ind1][ind2] = 0;
                else if (s1[ind1 - 1] == s2[ind2 - 1])
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];

                else
                    dp[ind1][ind2] = max(dp[ind1][ind2 - 1], dp[ind1 - 1][ind2]);
            }
        }

        return dp[n][m];
    }
};