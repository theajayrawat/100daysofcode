// Webpage:https://leetcode.com/problems/surrounded-regions/description/

class Solution {
public:
    void help(vector<vector<char>>& board,int i,int j){

        if(i<0||j<0||i==board.size()||j==board[0].size() || board[i][j]=='X' || board[i][j] == '1')
            return;

        board[i][j]='1';
        help(board,i+1,j);
        help(board,i,j+1);
        help(board,i-1,j);
        help(board,i,j-1);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && board[i][j] == 'O')
                    help(board, i, j);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O')
                board[i][j] = 'X';
            
                else if(board[i][j] == '1')
                    board[i][j] = 'O';
            }
        }
    }
};