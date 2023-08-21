// Link:https://practice.geeksforgeeks.org/problems/surround-the-1s2505/1
// Time Complexity: O(N*M)
// Space Complexity: O(1)

class Solution
{
public:
    bool solve(vector<vector<int>> &matrix, int i, int j, int n, int m)
    {
        vector<int> x = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> y = {-1, 0, 1, -1, 1, -1, 0, 1};

        int cnt = 0;

        for (int k = 0; k < x.size(); k++)
        {
            int X = i + x[k];
            int Y = j + y[k];
            if (X < 0 || Y < 0 || X == n || Y == m || matrix[X][Y] == 1)
                continue;
            else if (matrix[X][Y] == 0)
                cnt++;
        }

        return cnt % 2 == 0 && cnt;
    }
    int Count(vector<vector<int>> &matrix)
    {
        // Code here
        int n = matrix.size();
        int m = matrix[0].size();
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] && solve(matrix, i, j, n, m))
                    cnt++;
            }
        }

        return cnt;
    }
};