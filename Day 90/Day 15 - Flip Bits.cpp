// Link:https://practice.geeksforgeeks.org/problems/flip-bits0240/1
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        int tone = 0;
        for (int i = 0; i < n; i++)
            if (a[i])
                tone++;

        int zero = 0, maxzero = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
                zero++;
            else if (zero)
                zero--;
            maxzero = max(maxzero, zero);
        }

        return tone + maxzero;
    }
};