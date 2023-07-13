// Link:https://leetcode.com/problems/jump-game/?envType=list&envId=rvf6y046
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
    public boolean canJump(int[] nums) {
        int n=nums.length;
        int index=n-1;
        for(int i=n-2;i>=0;i--){
            if(i+nums[i]>=index)
                index=i;
        }

        return index==0;
    }
}