// Webpage:https://leetcode.com/problems/coin-change/description/

class Solution {
public:
    int help(vector<int>& coins, int amount, vector<int>&dp)
    {
        if(amount==0)
            return 0;
        if(amount<0)
            return INT_MAX;
        if(dp[amount])
            return dp[amount];

        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans=help(coins,amount-coins[i],dp);
            if(ans!=INT_MAX)
                mini=min(mini,ans+1);
        }

        return dp[amount]=mini;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,0);
        return help(coins,amount,dp)==INT_MAX?-1:help(coins,amount,dp);
    }
};