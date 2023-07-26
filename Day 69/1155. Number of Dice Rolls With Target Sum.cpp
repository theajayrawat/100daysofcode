// Link:https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
// Time Complexity: O(N * K)
// Space Complexity: O(N * K)

class Solution
{
public:
    int mod = 1e9 + 7;
    int solve(int n, int k, int target, vector<vector<int>> &dp)
    {
        if (n == 0 && target == 0)
        {
            return 1;
        }
        if (n == 0 || target <= 0)
            return 0;

        if (dp[n][target] != -1)
            return dp[n][target];
        int res = 0;
        for (int i = 1; i <= k; i++)
        {
            res = (res + solve(n - 1, k, target - i, dp) % mod) % mod;
        }

        return dp[n][target] = res % mod;
    }
    int numRollsToTarget(int n, int k, int target)
    {
        int ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solve(n, k, target, dp);
    }
};
