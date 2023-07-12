// Link:https://practice.geeksforgeeks.org/problems/find-nth-element-of-spiral-matrix/1
// Time Complexity: O(N^2)
// Space Complexity: O(1)

class Solution
{
public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX], int n, int m, int k)
    {
        // Your code goes here.
        int t = n * m;
        int start_col = 0;
        int start_row = 0;
        int end_col = m - 1;
        int end_row = n - 1;

        while (start_row <= end_row && start_col <= end_col)
        {
            for (int i = start_col; i <= end_col; i++)
            {
                k--;
                if (k == 0)
                    return a[start_row][i];
            }
            start_row++;

            for (int i = start_row; i <= end_row; i++)
            {
                k--;
                if (k == 0)
                    return a[i][end_col];
            }
            end_col--;

            for (int i = end_col; i >= start_col && start_row <= end_row; i--)
            {
                k--;
                if (k == 0)
                    return a[end_row][i];
            }
            end_row--;

            for (int i = end_row; i >= start_row && start_col <= end_col; i--)
            {
                k--;
                if (k == 0)
                    return a[i][start_col];
            }
            start_col++;
        }

        return -1;
    }
};
