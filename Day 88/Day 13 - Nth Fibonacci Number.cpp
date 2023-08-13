// Link:https://practice.geeksforgeeks.org/problems/nth-fibonacci-number1335/1
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution {
  public:
    int solve(int n, vector<int>&dp){
        if(dp[n]!=-1)
            return dp[n];
        if(n<=0)
            return 0;
        if(n==2 || n==1)
            return 1;
            
        return dp[n]=((solve(n-1,dp)%1000000007)+(solve(n-2,dp)%1000000007))%1000000007;
    }
    int nthFibonacci(int n){
        // code here
        vector<int>dp(n+1,-1);
        return solve(n,dp);
      
    }
};