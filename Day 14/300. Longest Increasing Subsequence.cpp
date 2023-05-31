// Webpage:https://leetcode.com/problems/longest-increasing-subsequence/description/

class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
        return solve(nums, 0, -1, dp);
    }
    int solve(vector<int>& nums, int i, int prev_i,vector<vector<int>>& dp) {
        if(i >= nums.size()) 
            return 0;
        if(dp[i][prev_i+1] != -1) 
            return dp[i][prev_i+1];

        int include= 0;
        if(prev_i == -1 || nums[i] > nums[prev_i]) 
            include = 1 + solve(nums, i + 1, i,dp);
        
        int exclude = 0 + solve(nums, i + 1, prev_i,dp);

        return dp[i][prev_i+1] = max(include, exclude);
    }
};