// Webpage:https://leetcode.com/problems/game-of-life/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>s(m,vector<int>(n,0));
        bool flag=true;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                int cnt=0;
                if(i>0&&j>0&&board[i-1][j-1]==1)cnt++;
                if(i>0&&board[i-1][j]==1)cnt++;
                if(j>0&&board[i][j-1]==1)cnt++;
                if(i>0&&j<n-1&&board[i-1][j+1]==1)cnt++;
                if(j>0&&i<m-1&&board[i+1][j-1]==1)cnt++;
                if(i<m-1&&j<n-1&&board[i+1][j+1]==1)cnt++;
                if(i<m-1&&board[i+1][j]==1)cnt++;
                if(j<n-1&&board[i][j+1]==1)cnt++;

                if(cnt<=1&&board[i][j]==1)s[i][j]=0; //Any live cell with fewer than two live neighbors dies as if caused by under-population.
                else if((cnt==2||cnt==3)&&flag&&board[i][j]==1)s[i][j]=1; //Any live cell with two or three live neighbors lives on to the next generation.
                else if(cnt==3&&board[i][j]==0)s[i][j]=1; //Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
                else if(cnt>3&&board[i][j]==1)s[i][j]=0;  //Any live cell with more than three live neighbors dies, as if by over-population.
                
            }
        }

        board=s;
    }
};