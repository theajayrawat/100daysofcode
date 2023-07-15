// Link:https://leetcode.com/problems/split-array-largest-sum/
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
    public int splitArray(int[] nums, int k) {
        int start=0;
        int end=0;
        int n=nums.length;

        for(int i=0;i<n;i++){
            start=Math.max(start,nums[i]);
            end+=nums[i];
        }

        while(start<end){
            int mid=start+(end-start)/2;

            int sum=0;
            int piece=1;
            for(int num:nums){
                if(sum+num>mid){
                    piece++;
                    sum=num;
                }
                else{
                    sum+=num;
                }
            }
            if(piece>k)start=mid+1;
            else end=mid;
        }
        return end;
    }

}