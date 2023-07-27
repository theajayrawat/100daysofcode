// Link:https://practice.geeksforgeeks.org/problems/handshakes1303/1
// Time Complexity: O(4^(N+M))
// Space Complexity: O(N*M*4*L) "L" length of word

class Solution
{
public:
    bool help(vector<vector<char>> &board, string word, vector<int> &dx, vector<int> &dy, int i, int j, int index)
    {
        if (index == word.size())
            return true;
        if (i < 0 || j < 0 || i == board.size() || j == board[0].size() || board[i][j] != word[index])
            return false;

        char s = board[i][j];
        board[i][j] = '.';
        bool ans = false;

        for (int k = 0; k < 4; k++)
        {
            ans |= help(board, word, dx, dy, i + dx[k], j + dy[k], index + 1);
        }

        board[i][j] = s;
        return ans;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        int m = board[0].size();
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0] && help(board, word, dx, dy, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};