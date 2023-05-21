// Webpage:https://leetcode.com/problems/unique-paths/description/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return help(m, n, 0, 0,dp);
    }

    int help(int m, int n,int i, int j, vector<vector<int>>&dp)
    {
        if(i==m-1 && j==n-1)
            return 1;
        if(i==m || j==n)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int a=help(m,n,i+1,j,dp);
        int b=help(m,n,i,j+1,dp);

        return dp[i][j]=a+b;
    }
};