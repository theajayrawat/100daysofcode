// Link:https://practice.geeksforgeeks.org/problems/coin-change2448/1
// Time Complexity: O(sum*N)
// Space Complexity: O(N)

class Solution
{
public:
    long long int count(int coins[], int N, int sum)
    {

        // code here.
        vector<vector<long long>> dp(N + 1, vector<long long>(sum + 1));

        for (int i = 0; i <= N; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 0; i <= sum; i++)
        {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (coins[i - 1] <= j)
                {
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[N][sum];
    }
};