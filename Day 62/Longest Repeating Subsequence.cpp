// Link:https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
// Time Complexity: O(N^2)
// Space Complexity: O(N^2)

class Solution
{
public:
    int LongestRepeatingSubsequence(string str)
    {
        // Code here
        string str1 = str;
        int n = str1.length(), m = str.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;

                else if (str1[i - 1] == str[j - 1] && i != j)
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[n][m];
    }
};
