// Link:https://practice.geeksforgeeks.org/problems/find-the-string-in-grid0111/1
// Time Complexity: O(N*M*K)
// Space Complexity: O(1)

class Solution
{
public:
    bool isCheck(vector<vector<char>> grid, int i, int j, int n, int m, string word)
    {

        int k = 0;
        int s = word.size();

        // Down
        for (int index = i; index < n && k < s; index++)
        {
            if (grid[index][j] != word[k])
                break;
            k++;
        }
        if (k == s)
            return true;

        // Up
        k = 0;
        for (int index = i; index >= 0 && k < s; index--)
        {
            if (grid[index][j] != word[k])
                break;
            k++;
        }
        if (k == s)
            return true;

        // right
        k = 0;
        for (int index = j; index < m && k < s; index++)
        {
            if (grid[i][index] != word[k])
                break;
            k++;
        }
        if (k == s)
            return true;

        // left
        k = 0;
        for (int index = j; index >= 0 && k < s; index--)
        {
            if (grid[i][index] != word[k])
                break;
            k++;
        }
        if (k == s)
            return true;

        // up-left
        k = 0;
        int in = i;
        for (int index = j; index >= 0 && in >= 0 && k < s; index--, in--)
        {
            if (grid[in][index] != word[k])
                break;
            k++;
        }
        if (k == s)
            return true;

        // up-right
        k = 0;
        in = i;
        for (int index = j; index < m && in >= 0 && k < s; index++, in--)
        {
            if (grid[in][index] != word[k])
                break;
            k++;
        }
        if (k == s)
            return true;

        // down-left
        k = 0;
        in = i;
        for (int index = j; index >= 0 && in < n && k < s; index--, in++)
        {
            if (grid[in][index] != word[k])
                break;
            k++;
        }
        if (k == s)
            return true;

        // down-right
        k = 0;
        in = i;
        for (int index = j; index < m && in < n && k < s; index++, in++)
        {
            if (grid[in][index] != word[k])
                break;
            k++;
        }
        if (k == s)
            return true;

        return false;
    }
    vector<vector<int>> searchWord(vector<vector<char>> grid, string word)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (isCheck(grid, i, j, n, m, word))
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};