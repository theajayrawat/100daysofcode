// Link:https://leetcode.com/problems/plus-one/?envType=list&envId=rvf6y046
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
    public int[] plusOne(int[] digits) {
        for (int i = digits.length - 1; i >= 0; i--) {
	        if (digits[i] < 9) {
		        digits[i]++;
		        return digits;
	        }
	        digits[i] = 0;
        }       

        digits = new int[digits.length + 1];
        digits[0] = 1;
        return digits;      
        
    }
}