// Webpage:https://leetcode.com/problems/house-robber/description/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;

        for(int i=1;i<nums.size();i++){
            int include=prev2+nums[i];
            int exclude=prev;
            prev2=prev;
            prev=max(include,exclude);
            
        }
        
        return prev;
    }
};