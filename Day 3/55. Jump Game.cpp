// Webpage:https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return help(nums,0,dp);
    }
    bool help(vector<int>&nums,int n,vector<int>&dp){
        if(n>=nums.size()-1)
            return true;
        if(nums[n]==0)
            return false;
        if(dp[n]!=-1)
            return dp[n];
        bool a=false;
        for(int i=1;i<=nums[n];i++){
            if(i<nums.size()&&help(nums,n+i,dp))
                return dp[n+i]=true;
        }
        return dp[n]=false;
    }
};