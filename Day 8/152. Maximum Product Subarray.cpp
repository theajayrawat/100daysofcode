// Webpage:https://leetcode.com/problems/maximum-product-subarray/description/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int j=0;
        int ans=nums[0],mx=nums[0],mi=nums[0];
        
        for(int i=1;i<n;i++){
            if(nums[i]<0)
                swap(mx,mi);
            mx=max(nums[i],mx*nums[i]);
            mi=min(nums[i],mi*nums[i]);
            ans=max(mx,ans);  
        }
        return ans;
    }
};