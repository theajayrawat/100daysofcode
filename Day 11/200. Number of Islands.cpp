// Webpage:https://leetcode.com/problems/number-of-islands/description/

class Solution {
public:
    void help(vector<vector<char>>& grid,int i,int j){
        if(i<0||j<0||i==grid.size()||j==grid[0].size() || grid[i][j]=='0')
            return;
       
        grid[i][j]='0';
        help(grid,i+1,j);
        help(grid,i,j+1);
        help(grid,i-1,j);
        help(grid,i,j-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1')
                {
                    cnt++;
                    help(grid,i,j);
                }
            }
        }

        return cnt;
    }

};