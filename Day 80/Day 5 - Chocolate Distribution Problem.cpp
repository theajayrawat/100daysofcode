// Link:https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        // code
        sort(a.begin(), a.end());

        if (n < m)
            return 0;

        long long ans = LLONG_MAX;

        for (int i = 0; i <= n - m; i++)
        {
            long diff = a[i + m - 1] - a[i];
            ans = min((long long)diff, ans);
        }

        return ans;
    }
};