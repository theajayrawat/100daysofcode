// Webpage:https://leetcode.com/problems/perfect-squares/

class Solution {
public:
    int help(int n,int cnt , vector<int>&dp)
    {
        if(n==0)
            return 0;
        
        if(dp[n]!=-1)
            return dp[n];
            
        int ans=n;
        for(int i=1;i*i<=n;i++)
        {
            ans=min(ans, 1+help(n-i*i,cnt+1,dp));
        }

        return dp[n]=ans;
    }

    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return help(n,0,dp);
    }
    
};