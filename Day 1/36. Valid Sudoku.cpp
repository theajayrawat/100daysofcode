// Website:https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9]={0};
        int col[9][9]={0};
        int box[3][3][9]={0};

        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                
                if(board[i][j]=='.')
                    continue;
                int num=board[i][j]-'1';
                if(row[i][num]++ || col[j][num]++ || box[i/3][j/3][num]++)
                    return false;
            }
        }

        return true;
    }
};