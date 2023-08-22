// Link:https://practice.geeksforgeeks.org/problems/make-matrix-beautiful-1587115620/1
// Time Complexity: O(N^2)
// Space Complexity: O(N)

class Solution
{
public:
    // Function to find minimum number of operations that are required
    // to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int>> matrix, int n)
    {
        // code here
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sum = sum + matrix[i][j];
            }
        }

        int rs = 0;
        int cs = 0;

        for (int i = 0; i < n; i++)
        {
            int a = 0;
            for (int j = 0; j < n; j++)
            {
                a = a + matrix[i][j];
            }
            rs = max(rs, a);

            int b = 0;
            for (int j = 0; j < n; j++)
            {
                b = b + matrix[j][i];
            }
            cs = max(cs, b);
        }

        int maxVal = max(cs, rs);

        return maxVal * n - sum;
    }
};
