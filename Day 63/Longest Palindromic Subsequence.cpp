// Link:https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1
// Time Complexity: O(N^2)
// Space Complexity: O(N^2)

class Solution
{
public:
    int longestPalinSubseq(string A)
    {
        // code here
        string rev = A;
        reverse(rev.begin(), rev.end());
        int n = A.length(), m = rev.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;

                else if (rev[i - 1] == A[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[n][m];
    }
};