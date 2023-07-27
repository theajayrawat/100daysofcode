// Link:https://practice.geeksforgeeks.org/problems/handshakes1303/1
// Time Complexity: O(2^(N/2))
// Space Complexity: O(1)

class Solution
{
public:
    int catalan(int n)
    {
        // Base case
        if (n <= 1)
            return 1;

        // catalan(n) is sum of
        // catalan(i)*catalan(n-i-1)
        int res = 0;
        for (int i = 0; i < n; i++)
            res += catalan(i) * catalan(n - i - 1);

        return res;
    }
    int count(int n)
    {
        // code here
        return catalan(n / 2);
    }
};