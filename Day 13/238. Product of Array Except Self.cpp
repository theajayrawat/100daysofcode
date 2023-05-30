// Webpage:https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {\
        int n=nums.size();

        vector<int>output(n);
        output[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            output[i]=output[i-1]*nums[i];
        }

        int product=1;
        for(int i=nums.size()-1;i>0;i--)
        {
            output[i]=output[i-1]*product;
            product*=nums[i];
        }

        output[0]=product;

        return output;
    }
};