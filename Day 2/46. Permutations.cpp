// Webpage:https://leetcode.com/problems/permutations/description/

class Solution {
public:
    void help(vector<int>& nums, vector<vector<int>>&ans, int i)
    {
        if(i==nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for(int j=i;j<nums.size();j++)
        {
            swap(nums[i],nums[j]);
            help(nums,ans,i+1);
            swap(nums[i],nums[j]);
        }
        
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        help(nums,ans,0);
        return ans;
    }
};