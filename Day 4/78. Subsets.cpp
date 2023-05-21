// Webpage:https://leetcode.com/problems/subsets/description/

class Solution {
public:
    void help(vector<vector<int>>&v,vector<int>& nums, vector<int>temp, int i)
    {
        if(i==nums.size())
        {
            v.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        help(v,nums,temp,i+1);
        temp.pop_back();
        help(v,nums,temp,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int>temp;
        help(v,nums,temp,0);

        return v;
    }
};