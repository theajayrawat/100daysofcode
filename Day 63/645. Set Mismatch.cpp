// Link:https://leetcode.com/problems/set-mismatch/
// Time Complexity:  O(N)
// Space Complexity: O(1)

class Solution
{
public
    int[] findErrorNums(int[] nums)
    {
        int i = 0;
        int n = nums.length;
        while (i < nums.length)
        {
            int index = nums[i] - 1;
            if (nums[i] != i + 1 && nums[i] != nums[index])
            {
                int temp = nums[i];
                nums[i] = nums[index];
                nums[index] = temp;
            }
            else
            {
                i++;
            }
        }
        for (i = 0; i < nums.length; i++)
        {
            if (nums[i] != i + 1)
                return new int[]{nums[i], i + 1};
        }
        return new int[]{-1, -1};
    }
}