// Link:https://leetcode.com/problems/shuffle-the-array/?envType=list&envId=rvf6y046
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
    public int[] shuffle(int[] nums, int n) {
        
        nums[0]*=-1;

        for(int i=1;i<nums.length/2;i++){
            int j=i;
            int currentNumber=nums[j];
            while(nums[j]>0){
                int target;
                if(j<n){
                    target=2*j;
                }
                else{
                    target=(j-n)*2+1;
                }

                int temp=nums[target];
                nums[target]=currentNumber;
                currentNumber=temp;
                nums[j]*=-1;
                j=target;
            }
        }

        for (int i = 0; i < nums.length; i++) {
            nums[i] = Math.abs(nums[i]);
        }

        return nums;
    }
}
