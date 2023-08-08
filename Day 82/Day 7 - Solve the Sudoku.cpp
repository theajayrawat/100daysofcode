// Link:https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1
// Time Complexity: O(9^(N*N))
// Space Complexity: O(1)

class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool isValid(int board[N][N], int row, int col, int c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c)
                return false;

            if (board[row][i] == c)
                 return false;

            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                 return false;
        }
        
        return true;
    }

    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j]==0){
                    for(int k=1;k<=9;k++){
                        if(isValid(grid, i, j, k)){
                            grid[i][j]=k;
                            if(SolveSudoku(grid))
                                return true;
                            else
                               grid[i][j]=0; 
                                
                        }
                    }
                    return false;
                }
                
            }
        }
        
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
            cout<<grid[i][j]<<" ";
                
            }
        }
        
    }
};