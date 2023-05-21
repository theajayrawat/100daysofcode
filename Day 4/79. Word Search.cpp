// Webpage:https://leetcode.com/problems/word-search/description/

class Solution {
public:
    bool help(vector<vector<char>>& board, string word,int i,int j,int n){
        if(n==word.size())
            return true;
        if(i<0 || j<0 || i==board.size() || j==board[0].size() || board[i][j]!=word[n])
            return false;

        char s=board[i][j];
        board[i][j]='-';
        bool left=help(board,word,i,j-1,n+1);
        bool right=help(board,word,i,j+1,n+1);
        bool up=help(board,word,i-1,j,n+1);
        bool down=help(board,word,i+1,j,n+1);
        board[i][j]=s;

        return left || right || up || down;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]&&help(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
        
    }
};