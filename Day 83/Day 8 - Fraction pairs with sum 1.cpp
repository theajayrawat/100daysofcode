// Link:https://practice.geeksforgeeks.org/problems/fraction-pairs-with-sum-1/1
// Time Complexity: O(N*log(max(numerator[])))
// Space Complexity: O(N)

class Solution
{
public:
    int solve(int a, int b)
    {
        if (b == 0)
            return a;

        return solve(b, a % b);
    }
    int countFractions(int n, int numerator[], int denominator[])
    {
        map<pair<int, int>, int> mp;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int gcd = solve(numerator[i], denominator[i]);
            numerator[i] /= gcd;
            denominator[i] /= gcd;

            int x = numerator[i];
            int y = denominator[i];

            int z = y - x;

            if (mp.count({z, y}))
                ans += mp[{z, y}];

            mp[{numerator[i], denominator[i]}]++;
        }

        return ans;
    }
};