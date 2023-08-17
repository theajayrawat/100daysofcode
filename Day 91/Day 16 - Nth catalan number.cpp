// Link:https://practice.geeksforgeeks.org/problems/nth-catalan-number0817/1
// Time Complexity: O(N^2)
// Space Complexity: O(N)

class Solution
{
public:
    // Function to find the nth catalan number.

    int findCatalan(int n)
    {
        // code here
        const int MOD = 1000000007;
        vector<long long> catalan(n + 1, 0);
        catalan[0] = catalan[1] = 1;

        for (int i = 2; i <= n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                catalan[i] = (catalan[i] + (catalan[j] * catalan[i - j - 1]) % MOD) % MOD;
            }
        }

        return catalan[n];
    }
};