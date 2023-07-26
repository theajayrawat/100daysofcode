// Link:https://practice.geeksforgeeks.org/problems/n-digit-numbers-with-digits-in-increasing-order5903/1
// Time Complexity: O(9^N)
// Space Complexity: O(N)

class Solution
{
public:
    void solve(int N, int n, vector<int> &v, int index)
    {
        if (N == 0)
        {
            v.push_back(n);
            return;
        }

        for (int i = index; i <= 9; i++)
        {
            n = n * 10 + i;
            solve(N - 1, n, v, i + 1);
            n = n / 10;
        }
    }
    vector<int> increasingNumbers(int N)
    {
        // Write Your Code here
        vector<int> v;
        if (N == 1)
            v.push_back(0);
        solve(N, 0, v, 1);
        return v;
    }
};