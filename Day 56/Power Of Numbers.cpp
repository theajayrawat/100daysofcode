// Link:https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1
// Time Complexity: O(LogN)
// Space Complexity: O(LogN)

class Solution
{
public:
    // You need to complete this fucntion
    int m = 1e9 + 7;
    long long power(int N, int R)
    {
        // Your code here
        if (R == 1)
            return N;
        if (R == 0)
            return 1;

        long long d = power(N, R / 2) % m;
        if (R % 2)
            return (((d * d) % m) * N) % m;
        else
            return (d * d) % m;
    }
};
