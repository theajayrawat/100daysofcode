// Link:https://practice.geeksforgeeks.org/problems/swapping-pairs-make-sum-equal4142/1
// Time Complexity: O(MlogM)
// Space Complexity: O(1)

class Solution
{

public:
    bool solve(int A_sum, int B_sum, int B[], int m)
    {

        int i = 0;
        int j = m - 1;

        while (i < j)
        {
            int mid = i + (j - i) / 2;
            int x = B[mid];
            if (A_sum + x == B_sum - x)
            {
                return true;
            }
            else if (A_sum + x > B_sum - x)
            {
                j = mid - 1;
            }
            else
                i = mid + 1;
        }

        return false;
    }
    int findSwapValues(int A[], int n, int B[], int m)
    {
        // Your code goes here
        if (n < m)
        {
            return findSwapValues(B, m, A, n);
        }

        sort(B, B + m);

        int B_sum = 0, A_sum = 0;

        for (int i = 0; i < n; i++)
        {
            A_sum += A[i];
        }

        for (int i = 0; i < m; i++)
        {
            B_sum += B[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (solve(A_sum - A[i], B_sum + A[i], B, m))
                return 1;
        }

        return -1;
    }
};