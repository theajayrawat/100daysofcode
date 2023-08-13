// Link:https://practice.geeksforgeeks.org/problems/edit-distance3702/1
// Time Complexity: O(M*N)
// Space Complexity: O(M*N)

class Solution {
  public:
    int solve(string s, string t, int i, int j,vector<vector<int>>&dp){
        if(i==0)
            return j;
        if(j==0)
            return i;
        
        if(dp[i-1][j-1]!=-1)
            return dp[i-1][j-1];
        
        if(s[i-1]==t[j-1])
           return solve(s,t,i-1,j-1,dp);
        
        int ins=solve(s,t,i,j-1,dp);
        int remo=solve(s,t,i-1,j,dp);
        int rep=solve(s,t,i-1,j-1,dp);
        
        return dp[i-1][j-1]=1 + min(ins,min(remo,rep));
    }
    int editDistance(string s, string t) {
        // Code here
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        return solve(s,t,s.size(),t.size(),dp);
    }
};