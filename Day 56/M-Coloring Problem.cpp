// Link:https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1
// Time Complexity: O( N^M)
// Space Complexity: O(N)

bool isSafe(vector<vector<int>> &mat, int n, int node, vector<int> &color, int col)
{
    for (int i = 0; i < n; i++)
    {
        if (i != node && mat[i][node] == 1 && color[i] == col)
            return false;
    }

    return true;
}
bool solve(vector<vector<int>> &mat, int n, int m, int node, vector<int> &color)
{
    if (n == node)
        return true;

    for (int i = 1; i <= m; i++)
    {
        if (isSafe(mat, n, node, color, i))
        {
            color[node] = i;
            if (solve(mat, n, m, node + 1, color))
                return true;
            color[node] = 0;
        }
    }

    return false;
}
string graphColoring(vector<vector<int>> &mat, int m)
{
    // Write your code here
    int n = mat.size();
    vector<int> color(n, 0);
    if (solve(mat, n, m, 0, color))
        return "YES";
    return "NO";
}