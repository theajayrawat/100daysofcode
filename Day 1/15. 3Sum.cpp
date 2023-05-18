// Website:https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;

        for(int i=0;i<n-2;i++)
        {
            while(i != 0 && i < n-2 && nums[i-1] == nums[i])
                i++;
            
            int j=i+1;
            int k=n-1;
            int target= -nums[i];
            while(j<k)
            {
                int sum=nums[j]+nums[k];
                if(sum==target)
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                    
                else if(sum>target)
                    k--;
                else 
                    j++;

                while(j!=i+1 && j < k &&  nums[j]==nums[j-1])
                    j++;    
                while(k!=n-1 && j < k && nums[k+1]==nums[k])
                    k--;

            }
        }

        return ans;
    }
};