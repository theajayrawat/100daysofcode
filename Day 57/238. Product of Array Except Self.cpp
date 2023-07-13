// Link:https://leetcode.com/problems/product-of-array-except-self/?envType=list&envId=rvf6y046
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n=nums.length;
        int[] output=new int[n];

        output[0]=nums[0];
        for(int i=1;i<n;i++){
            output[i]=output[i-1]*nums[i];
        }

        int product=1;
        for(int i=n-1;i>0;i--){
            output[i]=output[i-1]*product;
            product*=nums[i];
        }

        output[0]=product;
        return output;

    }
}